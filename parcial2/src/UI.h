/*
 * UI.h
 *
 *  Created on: Oct 5, 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef UI_H_
#define UI_H_

int orquestaUIAlta(Orquesta *list, int len);
int orquestaUIModificacion(Orquesta *list, int len);
int orquestaUIBaja(Orquesta *list, int len);
int instrumentoUIAlta(Instrumento *list, int len);
int musicoUIAlta(Musico *list, int len, Instrumento *list2, int len2, Orquesta *list3, int len3);
int musicoUIModificacion(Musico *list, int len, Orquesta *list2, int len2);
int musicoUIBaja(Musico *list, int len);

#endif /* UI_H_ */
