/*
 * BitMath.h
 *
 * Created: 9/30/2022 7:01:51 PM
 *  Author: User
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) Reg |= (1<<BitNo)
#define ClearBit(Reg,BitNo) Reg &= ~(1<<BitNo)
#define ToggleBit(Reg,BitNo) Reg ^= (1<<BitNo)
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)


#endif /* BITMATH_H_ */