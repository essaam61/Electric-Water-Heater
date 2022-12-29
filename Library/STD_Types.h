/*
 * STD_Types.h
 *
 * Created: 9/30/2022 7:27:09 PM
 *  Author: User
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;

typedef enum {
	STD_Low=0,
	STD_High	
	}STD_LevelType;

typedef enum{
	FALSE,
	TRUE
	}boolean;

/* NULL_PTR define with a void pointer to zero definition*/
#define NULL_PTR       ((void *)0)

#endif /* STD_TYPES_H_ */