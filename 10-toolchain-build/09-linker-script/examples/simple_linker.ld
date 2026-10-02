/**
 * @file simple_linker.ld
 * @brief A fully functional, simplified Linker Script for an STM32.
 */

/* The Entry Point (where hardware execution begins) */
ENTRY(Reset_Handler)

/* The Physical Memory Map (From the Datasheet) */
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
  RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
  /* 1. CODE AND CONSTANTS (Stored and Executed in Flash) */
  .text :
  {
    *(.isr_vector) /* The Vector Table MUST be at the very beginning of Flash */
    *(.text)       /* All function code */
    *(.rodata)     /* All const variables */
  } > FLASH

  /* Remember the current Flash address so we can store initial data values here */
  _sidata = LOADADDR(.data);

  /* 2. INITIALIZED VARIABLES (Stored in Flash, Run in RAM) */
  .data :
  {
    _sdata = .;    /* Provide C++ with the Start address of RAM .data */
    *(.data)       /* Initialized global variables (e.g., int x = 5) */
    _edata = .;    /* Provide C++ with the End address of RAM .data */
  } > RAM AT > FLASH

  /* 3. UNINITIALIZED VARIABLES (Run in RAM. No initial values to store) */
  .bss :
  {
    _sbss = .;     /* Provide C++ with the Start address of RAM .bss */
    *(.bss)        /* Uninitialized global variables (e.g., int y;) */
    _ebss = .;     /* Provide C++ with the End address of RAM .bss */
  } > RAM
}
