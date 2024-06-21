#ifndef __ILI9341_H
#define __ILI9341_H

#pragma region Registers Definitions
typedef enum
{
    NOP                     = 0x00,
    SoftwareReset           = 0x01,
    ReadDisplayID           = 0x04,
    ReadDisplayStatus       = 0x09,
    ReadPowerMode           = 0x0A,
    ReadMADCTL              = 0x0B,
    ReadPixelFormat         = 0x0C,
    ReadImageFormat         = 0x0D,
    ReadSignalMode          = 0x0E,
    ReadSelfDiagnostic      = 0x0F,
    EnterSleepMode          = 0x10,
    SleepOut                = 0x11,
    PartialModeON           = 0x12,
    NormalDisplayModeON     = 0x13,
    DisplayInversionOFF     = 0x20,
    DisplayInversionON      = 0x21,
    GammaSet                = 0x26,
    DisplayOFF              = 0x28,
    DisplayON               = 0x29,
    CASET                   = 0x2A, //Column Address set
    PASET                   = 0x2B, //Page Address Set
    MemoryWrite             = 0x2C,
    ColorSet                = 0x2D,
    MemoryRead              = 0x2E,
    PartialArea             = 0x30,
    VerticalScrollDef       = 0x33,
    TearingEffectLineOFF    = 0x34,
    TearingEffectLineON     = 0x35,
    MemoryAccessControl     = 0x36,
    VerticalScrollStartAddr = 0x37,
    IdleModeOFF             = 0x38,
    IdleModeON              = 0x39,
    PixelFormatSet          = 0x3A,
    WriteMemoryContinue     = 0x3C,
    ReadMemoryContinue      = 0x3E,
    SetTearScanline         = 0x44,
    GetScanline             = 0x45,
    WriteDisplayBrightness  = 0x51,
    ReadDisplayBrightness   = 0x52,
    WriteCTRLDisplay        = 0x53,
    ReadCTRLDisplay         = 0x54,
    WriteCABC               = 0x55, //Write Content Adaptive Brightness Control
    ReadCABC                = 0x56, //Read Content Adaptive Brightness Control
    WriteMinCABC            = 0x5E,
    ReadMinCABC             = 0x5F,
    ReadID1                 = 0xDA,
    ReadID2                 = 0xDB,
    ReadID3                 = 0xDC,

} ILI9341_Regs;

typedef enum
{
    RGBSignalControl        = 0xB0,
    FramControlNormalMode   = 0xB1,
    FramControlIdleMode     = 0xB2,
    FramControlPartialMode  = 0xB3,
    DisplayInversionControl = 0xB4,
    BlankingPorchControl    = 0xB5,
    DisplayFunctionControl  = 0xB6,
    EntryModeSet            = 0xB7,
    BacklightControl1       = 0xB8,
    BacklightControl2       = 0xB9,
    BacklightControl3       = 0xBA,
    BacklightControl4       = 0xBB,
    BacklightControl5       = 0xBC,
    BacklightControl6       = 0xBD,
    BacklightControl7       = 0xBE,
    BacklightControl8       = 0xBF,
    PowerControl1           = 0xC0,
    PowerControl2           = 0xC1,
    VCOMControl1            = 0xC5,
    VCOMControl2            = 0xC5,
    NVMemoryWrite           = 0xD0,
    NVMemmoryProtectionKey  = 0xD1,
    NVMemmoryStatusRead     = 0xD2,
    ReadID4                 = 0xD3,
    PositiveGammaCorrection = 0xE0,
    NegativeGammaCorrection = 0xE1,
    DigitalGammaControl1    = 0xE2,
    DigitalGammaControl2    = 0xE3,
    InterfaceControl        = 0xF6,
    PowerControlA           = 0xCB,
    PowerControlB           = 0xCF,
    DriverTimingControlA    = 0xE8,
    DriverTimingControlB    = 0xE9,
    DriverTimingControlC    = 0xEA,
    PowerOnSequenceControl  = 0xED,
    Enable3G                = 0xF2


} ILI9341_Regs_Ext;
#pragma endregion 

namespace Drivers::Interfaces
{
    class Ili9341
    {
        public:
            Ili9341();
            ~Ili9341();
            
    };
}


#endif /* __ILI9341_H */
