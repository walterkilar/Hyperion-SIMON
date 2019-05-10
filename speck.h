/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * @author	Walt Kilar 2019
 * @file	speck.h
 * @brief	Helper functions for the Speck block cipher
 * @ref		https://eprint.iacr.org/2013/404.pdf
 * @todo	none
 * 
*/
#ifndef SPECK_H
#define SPECK_H

#include "cipher_constants.h"

typedef struct _bitword24_t{
  uint32_t data: 24;
} bitword24_t;

typedef struct _bytes3_t{
        uint8_t data[3];
} bytes3_t;

typedef struct _bitword48_t{
  uint64_t data: 48;
} bitword48_t;

typedef struct _bytes6_t{
        uint8_t data[6];
} bytes6_t;


uint8_t Speck_Init(SimSpk_Cipher *cipher_object, enum cipher_config_t cipher_cfg, enum mode_t c_mode, void *key, uint8_t *iv, uint8_t *counter);

uint8_t Speck_Encrypt(SimSpk_Cipher cipher_object, const void *plaintext, void *ciphertext);

uint8_t Speck_Decrypt(SimSpk_Cipher cipher_object, const void *ciphertext, void *plaintext);

void Speck_Encrypt_32(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *plaintext,
                      uint8_t *ciphertext);
void Speck_Encrypt_48(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *plaintext,
                      uint8_t *ciphertext);
void Speck_Encrypt_64(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *plaintext,
                      uint8_t *ciphertext);
void Speck_Encrypt_96(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *plaintext,
                      uint8_t *ciphertext);
void Speck_Encrypt_128(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *plaintext,
                       uint8_t *ciphertext);

void Speck_Decrypt_32(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *ciphertext,
                      uint8_t *plaintext);
void Speck_Decrypt_48(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *ciphertext,
                      uint8_t *plaintext);
void Speck_Decrypt_64(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *ciphertext,
                      uint8_t *plaintext);
void Speck_Decrypt_96(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *ciphertext,
                      uint8_t *plaintext);
void Speck_Decrypt_128(const uint8_t round_limit, const uint8_t *key_schedule, const uint8_t *ciphertext,
                       uint8_t *plaintext);

#endif
