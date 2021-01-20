/*
 * file:	usart.h
 * author:	makarpi
 * brief:	
 */

#ifndef _USART_H_
#define _USART_H_

void usart_init(void);
void usart_puts(USART_TypeDef *pUsart, uint8_t *str);

#endif /* _USART_H_ */
