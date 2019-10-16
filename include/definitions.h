#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "SDL2/SDL.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define TILE_SIZE 32
#define ATLAS_RES 16

#define min(x, y) (x < y? x:y)
#define max(x, y) (x < y? y:x)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32; 
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;


typedef enum {
	UP = 0,
	RIGHT,
	DOWN,
	LEFT,
}MovementType;


#endif