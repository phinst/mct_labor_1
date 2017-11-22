/* 
 * File:   read_write.h
 * Author: finst
 *
 * Created on 21. November 2017, 11:54
 */

#ifndef READ_WRITE_H
#define	READ_WRITE_H

#ifdef	__cplusplus
extern "C" {
#endif

    extern void d_write(int pinnummer, int value);
    extern int d_read(int pinnummer);
    extern unsigned int a_read(int pinnummer);


#ifdef	__cplusplus
}
#endif

#endif	/* READ_WRITE_H */

