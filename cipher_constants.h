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
 * @file	cipher_constants.h
 * @brief	Helper functions common to Simon and Speck encryption/decryption
 * @ref		https://eprint.iacr.org/2013/404.pdf
 * @todo	none
 * 
*/
// cipher_constants.h
#ifndef CIPHER_CONSTANTS_H
#define CIPHER_CONSTANTS_H

enum mode_t { ECB, CTR, CBC, CFB, OFB };

static const uint8_t block_sizes[] = {32, 48, 48, 64, 64, 96, 96, 128, 128, 128};

static const uint16_t key_sizes[] = {64, 72, 96, 96, 128, 96, 144, 128, 192, 256};

enum cipher_config_t {
    cfg_64_32,
    cfg_72_48,
    cfg_96_48,
    cfg_96_64,
    cfg_128_64,
    cfg_96_96,
    cfg_144_96,
    cfg_128_128,
    cfg_192_128,
    cfg_256_128
} ;

typedef struct {
    enum cipher_config_t cipher_cfg;
    void (*encryptPtr)(const uint8_t, const uint8_t *, const uint8_t *, uint8_t *);
    void (*decryptPtr)(const uint8_t, const uint8_t *, const uint8_t *, uint8_t *);
    uint16_t key_size;
    uint8_t block_size;
    uint8_t round_limit;
    uint8_t init_vector[16];
    uint8_t counter[16];
    uint8_t key_schedule[576];
    uint8_t alpha;
    uint8_t beta;
    uint8_t z_seq;
} SimSpk_Cipher;

#endif
