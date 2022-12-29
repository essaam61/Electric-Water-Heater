/*
 * EINT_Types.h
 *
 * Created: 10/7/2022 9:05:42 PM
 *  Author: User
 */ 


#ifndef EINT_TYPES_H_
#define EINT_TYPES_H_

#define GICR_INT0_Bit 6
#define GICR_INT1_Bit 7
#define GICR_INT2_Bit 8

#define MCUCSR_INT2_ISC2_Bit 6

typedef enum{
	Ext_INT0=0,
	Ext_INT1,
	Ext_INT2
}ExtINT_Type;


typedef enum{
	Low_Level=0,
	Both_Edge,
	Rising_Edge,
	Falling_Edge
}ExtISC_Type;


#endif /* EINT_TYPES_H_ */