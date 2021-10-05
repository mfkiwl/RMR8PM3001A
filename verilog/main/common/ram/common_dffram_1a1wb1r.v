// @description
//  ** PART OF **
//  RMR8PM3001A - Taurus 3001
//  (RISC-V 64-bit Privileged Minimal System Processor for T110 ASIC)
//
//  DFF-base RAM module with Bit Write Enable
//
// @author Kumonda221
//

`define     RAM_DEPTH       (1 << RAM_ADDR_WIDTH)

module common_dffram_1a1wb1r #(
    parameter                   RAM_DATA_WIDTH      = 5,
    parameter                   RAM_ADDR_WIDTH      = 4,
    parameter [`RAM_DEPTH:0]    RAM_RESET_VALUE     = { (`RAM_DEPTH){ {(RAM_ADDR_WIDTH){1'b0}} } }
) (
    input   wire                            clk,
    input   wire                            reset,

    input   wire [RAM_ADDR_WIDTH - 1:0]     addr,
    input   wire                            en,
    input   wire [RAM_DATA_WIDTH - 1:0]     we,

    input   wire [RAM_DATA_WIDTH - 1:0]     din,
    output  wire [RAM_DATA_WIDTH - 1:0]     dout
);

    //
    localparam  RAM_DEPTH   = `RAM_DEPTH;

    wire [RAM_DATA_WIDTH - 1:0]     dff_dout [RAM_DEPTH - 1:0];

    genvar i;
    generate
        for (i = 0; i < RAM_DEPTH; i = i + 1) begin :GENERATED_RAM_DFFS

            //
            wire [RAM_DATA_WIDTH - 1:0]     dff_we;

            stdmacro_dffe #(
                .DFF_WIDTH          (RAM_DATA_WIDTH),
                .DFF_RESET_VALUE    (RAM_RESET_VALUE[i])
            ) stdmacro_dffe_INST_dffram_dff (
                .clk(clk),
                .reset(reset),

                .en(dff_we),
                .d(din),

                .q(dff_dout[i])
            );

            assign dff_we  = we & { (RAM_DATA_WIDTH){en} } & { (RAM_DATA_WIDTH){addr == i} };
            //
        end
    endgenerate

    //
    assign  dout = dff_dout[addr];

    //

endmodule
