#pragma once
//
// RISC-V Instruction Set Architecture CSR (Control and Status Register)
//
// Machine ISA Register 'misa'
//

#include "riscvcsr.hpp"

#define CSR_misa_FIELD_MXL_DEF_XLEN32                   1
#define CSR_misa_FIELD_MXL_DEF_XLEN64                   2
#define CSR_misa_FIELD_MXL_DEF_XLEN128                  3


#define CSR_misa_FIELD_EXTENSION_MASK                   0x03FFFFFF
#define CSR_misa_FIELD_EXTENSION_OFFSET                 0

#define CSR_misa_BIT_A                                  0x00000001
#define CSR_misa_BIT_B                                  0x00000002
#define CSR_misa_BIT_C                                  0x00000004
#define CSR_misa_BIT_D                                  0x00000008
#define CSR_misa_BIT_E                                  0x00000010
#define CSR_misa_BIT_F                                  0x00000020
#define CSR_misa_BIT_G                                  0x00000040
#define CSR_misa_BIT_H                                  0x00000080
#define CSR_misa_BIT_I                                  0x00000100
#define CSR_misa_BIT_J                                  0x00000200
#define CSR_misa_BIT_K                                  0x00000400
#define CSR_misa_BIT_L                                  0x00000800
#define CSR_misa_BIT_M                                  0x00001000
#define CSR_misa_BIT_N                                  0x00002000
#define CSR_misa_BIT_O                                  0x00004000
#define CSR_misa_BIT_P                                  0x00008000
#define CSR_misa_BIT_Q                                  0x00010000
#define CSR_misa_BIT_R                                  0x00020000
#define CSR_misa_BIT_S                                  0x00040000
#define CSR_misa_BIT_T                                  0x00080000
#define CSR_misa_BIT_U                                  0x00100000
#define CSR_misa_BIT_V                                  0x00200000
#define CSR_misa_BIT_W                                  0x00400000
#define CSR_misa_BIT_X                                  0x00800000
#define CSR_misa_BIT_Y                                  0x01000000
#define CSR_misa_BIT_Z                                  0x02000000


#define CSR_misa_BIT_ATMOIC_EXTENSION                   CSR_misa_BIT_A  // Atomic extension
#define CSR_misa_BIT_COMPRESSED_EXTENSION               CSR_misa_BIT_C  // Compressed extension
#define CSR_misa_BIT_DOUBLE_FLOAT_EXTENSION             CSR_misa_BIT_D  // Double-precision floating-point extension
#define CSR_misa_BIT_RV32E_BASE                         CSR_misa_BIT_E  // RV32E base ISA
#define CSR_misa_BIT_SINGLE_FLOAT_EXTENSION             CSR_misa_BIT_F  // Single-precision floating-point extension
#define CSR_misa_BIT_ADDITIONAL_STANDARD_EXTENSIONS     CSR_misa_BIT_G  // Additional standard extensions present
#define CSR_misa_BIT_HYPERVISOR_EXTENSION               CSR_misa_BIT_H  // Hypervisor extension
#define CSR_misa_BIT_RVxI_BASE                          CSR_misa_BIT_I  // RV32I/64I/128I base ISA
#define CSR_misa_BIT_INTEGER_MULDIV_EXTENSION           CSR_misa_BIT_M  // Integer Multiply/Divide extension
#define CSR_misa_BIT_USER_INTERRUPTS                    CSR_misa_BIT_N  // User-level interrupts supported
#define CSR_misa_BIT_QUAD_FLOAT_EXTENSION               CSR_misa_BIT_Q  // Quad-precision floating-point extension
#define CSR_misa_BIT_SUPERVISOR_MODE                    CSR_misa_BIT_S  // Supervisor mode implemented
#define CSR_misa_BIT_USER_MODE                          CSR_misa_BIT_U  // User mode implemented
#define CSR_misa_BIT_NONSTANDARD_EXTENSIONS             CSR_misa_BIT_X  // Non-standard extensions present
 
#define CSR_misa_DEFAULT_AT_COMPILE                     0


namespace Jasse::CSR {

    class RVCSR_misa : public RVCSR {
    private:
        csr_t   value;

    public:
        RVCSR_misa();
        RVCSR_misa(const RVCSR_misa& obj);
        ~RVCSR_misa();

        virtual RVCSR*          Clone();

        virtual csr_t           GetValue() noexcept;
        virtual void            SetValue(csr_t value) noexcept;
    };

    // CSR 'misa' instance allocator
    RVCSR* __allocator_RVCSR_misa()
    {
        return new RVCSR_misa();
    }

    // CSR 'misa' definition field
    static const RVCSRDefinition misa = { CSR_misa, &__allocator_RVCSR_misa };
}


// Implementation of: class RVCSR_misa
namespace Jasse::CSR {
    /*
    csr_t   value;
    */

    RVCSR_misa::RVCSR_misa()
        : RVCSR (CSR_misa, "misa")
        , value (CSR_misa_DEFAULT_AT_COMPILE)
    { }

    RVCSR_misa::RVCSR_misa(const RVCSR_misa& obj)
        : RVCSR (obj)
        , value (obj.value)
    { }

    RVCSR_misa::~RVCSR_misa()
    { }

    RVCSR* RVCSR_misa::Clone()
    {
        return new RVCSR_misa(*this);
    }

    csr_t RVCSR_misa::GetValue() noexcept
    {
        return value;
    }

    void RVCSR_misa::SetValue(csr_t value) noexcept
    {
        this->value = value;
    }
}

