/* Entry Point */
ENTRY(Reset_Handler)

/* Highest address of the user mode stack */
_estack = ORIGIN(SRAM) + LENGTH(SRAM); /* end of "RAM" Ram type memory */

_Min_Heap_Size = 0x200; /* required amount of heap */
_Min_Stack_Size = 0x400; /* required amount of stack */

/* Memories definition */
MEMORY
{
  SRAM    (rwx)    : ORIGIN = 0x20000000,   LENGTH = 20K
  FLASH    (rx)    : ORIGIN = 0x08000000,   LENGTH = 64K
}

/*Sections*/
SECTIONS
{
     /*first section of output file*/
	.text :
	{
	  . = ALIGN(4);
	  *(.isr_vector_tbl)  /*merge all .isr_vector_tbl sections of input files*/
	  *(.text)             /*merge all .text sections of input files*/
	  *(.rodata)           /*merge all .rodata sections of input files*/
	  . = ALIGN(4);
	 _etext = .;          /*Create a global symbol to hold end of text section*/
	}>FLASH
	    

    /*second section of output file*/
	
	.data :
	{
	 . = ALIGN(4);
	_sdata = .;   /*Create a global symbol to hold start of data section*/
	  *(.data)
	 . = ALIGN(4);
	_edata = .;   /*Create a global symbol to hold end of data section*/
	} > SRAM AT> FLASH  /*>(vma) AT> (lma)*/
	
	
	/*third section of output file*/
	.bss :
	{
	 . = ALIGN(4);
	_sbss = .;  /*Create a global symbol to hold start of bss section*/
	*(.bss)  /*merge all .bss sections of input files*/
	 . = ALIGN(4);
	_ebss = .;  /*Create a global symbol to hold end of bss section*/
	}> SRAM
	

}
