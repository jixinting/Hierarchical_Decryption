/*************************************************************************/
/*                librairie.h : ENTETE                                   */
/*		       							 */
/*       libriairie de fonctions pour    				 */
/*             la manipulation d'images au format .raw ou .pgm           */
/*									 */
/*									 */
/*           Auteur : William Puech					 */
/* 		    puech@univ-montp2.fr				 */
/*									 */
/*									 */
/*************************************************************************/

/* les "include" (fichiers d'entetes) -----------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* nouveaux types -------------------------------------------------------*/

typedef unsigned char OCTET;

#define PI 3.14159265359

#define AES_BLOCKBITS 128
#define TAILLEBLOCKBYTE 16
#define TAILLEBLOCKHEX 32
#define uint unsigned int
//#define OCTET unsigned char

#define HOTWORD(z) ((uint)(z) >> 24) | (z << 8 )
#define GETBIT(z, b) ( (z & (1 << b)) >> b)
#define GETOCTET(z, s) ( (uint)(z) << (s*8) ) >> 24
#define PUTOCTET(z, r, s)  z &= ~(((uint)(0xff)) << (24 - 8*s)); z |= ((uint)(r)) << (24 - 8*s);

#include "Rijndael.tab"
/* declarations de fonctions --------------------------------------------*/

int init(char **ch);

void inttochar(int, char[]);

void inverser(char[]);

void produit_matriciel(double*, double*, double*, int);

void produit_matriciel_OCTET(OCTET*, double*, double*, int);

uint* _32HexTo4UintLin(OCTET[]);
extern "C"  MY3DSTEGANOGRAPHY_API void _32HexTo4UintCol(const OCTET c[32], uint WordBin[4]);
extern "C"  MY3DSTEGANOGRAPHY_API uint GetS_BOX(uint c);
extern "C"  MY3DSTEGANOGRAPHY_API uint InvGetS_BOX(uint c);
extern "C"  MY3DSTEGANOGRAPHY_API void KeySchedule(const OCTET KeyOrig[64], uint RoundKey[15][4]);
extern "C"  MY3DSTEGANOGRAPHY_API void ShiftRow(uint WBinIn[4]);
extern "C"  MY3DSTEGANOGRAPHY_API void InvShiftRow(uint WBinIn[4]);
extern "C"  MY3DSTEGANOGRAPHY_API void MixColumn(uint WBinIn[4]);
extern "C"  MY3DSTEGANOGRAPHY_API void InvMixColumn(uint WBinIn[4]);
extern "C"  MY3DSTEGANOGRAPHY_API uint GaloisMultAES(OCTET v1, OCTET v2);
extern "C"  MY3DSTEGANOGRAPHY_API unsigned char hexa2uc(char c);
extern "C"  MY3DSTEGANOGRAPHY_API uint * EncrypterAES(uint WordBin[4]);
extern "C"  MY3DSTEGANOGRAPHY_API OCTET * EncrypterAESMode(const OCTET c[16]);
extern "C"  MY3DSTEGANOGRAPHY_API uint * DecrypterAES(const uint WordBin[4]);
extern "C"  MY3DSTEGANOGRAPHY_API OCTET * DecrypterAESMode(const OCTET c[16]);

/*==================================================================*/
/*==================================================================*/
