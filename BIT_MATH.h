#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(reg,bit)			reg|=(1<<bit)
#define	CLEAR_BIT(reg,bit)		    reg&=~(1<<bit)
#define TOG_BIT(reg,bit)		    reg^=(1<<bit)
#define READ_BIT(reg,bit)			reg =(reg>>bit)&1






#endif /* STD_MACROS_H_ */