// @description
//  ** PART OF **
//  RMR8PM3001A - Taurus 3001
//  (RISC-V 64-bit Privileged Minimal System Processor for T110 ASIC)
//
//  Standard DFF Module with Low-Active Synchronous Reset
//
// @author Kumonda221
//

module std_dffrn # ( 
    parameter   DFF_WIDTH       = 1
) (
    input   wire                        clk,
    input   wire                        resetn,

    input   wire [DFF_WIDTH - 1:0]      d,
    output  wire [DFF_WIDTH - 1:0]      q
);

    reg  [DFF_WIDTH - 1:0]  q_R;

    always @(posedge clk) begin
        
        if (~resetn) begin
            q_R <= 'b0;
        end
        else begin
            q_R <= d;
        end
    end

    assign q = q_R;

endmodule