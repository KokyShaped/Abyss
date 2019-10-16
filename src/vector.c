#include "vector.h"

Vector2 addVectors(Vector2 a, Vector2 b){
	Vector2 rtn;
	rtn.x = a.x + b.x;
	rtn.y = a.y + b.y;
	return rtn;
}
