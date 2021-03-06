#ifndef _H_MATH_VECTORS_
#define _H_MATH_VECTORS_

#define RAD2DEG(x) (x * 57.295754f)
#define DEG2RAD(x) (x * 0.0174533f)

typedef struct vec2 {
	union {
		struct {
			float x;
			float y;
		};
		float asArray[2];
	};

	inline float& operator[](int i) {
		return asArray[i];
	}

#ifndef NO_EXTRAS
	inline vec2() : x(0.0f), y(0.0f) { }
	inline vec2(float _x, float _y) : x(_x), y(_y) { }
#endif
} vec2;

typedef struct vec3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float asArray[3];
	};

	inline float& operator[](int i) {
		return asArray[i];
	}
	
#ifndef NO_EXTRAS
	inline vec3() : x(0.0f), y(0.0f), z(0.0f) { }
	inline vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }
#endif
} vec3;

vec2 operator+(const vec2& l, const vec2& r);
vec3 operator+(const vec3& l, const vec3& r);

vec2 operator-(const vec2& l, const vec2& r);
vec3 operator-(const vec3& l, const vec3& r);

vec2 operator*(const vec2& l, const vec2& r);
vec3 operator*(const vec3& l, const vec3& r);

vec2 operator*(const vec2& l, float r);
vec3 operator*(const vec3& l, float r);

#ifndef NO_EXTRAS
vec2 operator/(const vec2& l, const vec2& r);
vec3 operator/(const vec3& l, const vec3& r);

vec2 operator/(const vec2& l, float r);
vec3 operator/(const vec3& l, float r);
#endif

bool operator==(const vec2& l, const vec2& r);
bool operator==(const vec3& l, const vec3& r);

bool operator!=(const vec2& l, const vec2& r);
bool operator!=(const vec3& l, const vec3& r);

#ifndef NO_EXTRAS
vec2& operator+=(vec2& l, const vec2& r);
vec2& operator-=(vec2& l, const vec2& r);
vec2& operator*=(vec2& l, const vec2& r);
vec2& operator*=(vec2& l, const float r);
vec2& operator/=(vec2& l, const vec2& r);
vec2& operator/=(vec2& l, const float r);

vec3& operator+=(vec3& l, const vec3& r);
vec3& operator-=(vec3& l, const vec3& r);
vec3& operator*=(vec3& l, const vec3& r);
vec3& operator*=(vec3& l, const float r);
vec3& operator/=(vec3& l, const vec3& r);
vec3& operator/=(vec3& l, const float r);
#endif

float Dot(const vec2& l, const vec2& r);
float Dot(const vec3& l, const vec3& r);

float Magnitude(const vec2& v);
float Magnitude(const vec3& v);

float MagnitudeSq(const vec2& v);
float MagnitudeSq(const vec3& v);

#ifndef NO_EXTRAS
float Distance(const vec2& p1, const vec2& p2);
float Distance(const vec3& p1, const vec3& p2);

float DistanceSq(const vec2& p1, const vec2& p2);
float DistanceSq(const vec3& p1, const vec3& p2);
#endif

void Normalize(vec2& v);
void Normalize(vec3& v);

vec2 Normalized(const vec2& v);
vec3 Normalized(const vec3& v);

vec3 Cross(const vec3& l, const vec3& r);

float Angle(const vec2& l, const vec2& r);
float Angle(const vec3& l, const vec3& r);

vec2 Project(const vec2& length, const vec2& direction);
vec3 Project(const vec3& length, const vec3& direction);

vec2 Perpendicular(const vec2& length, const vec2& direction);
vec3 Perpendicular(const vec3& length, const vec3& direction);

vec2 Reflection(const vec2& sourceVector, const vec2& normal);
vec3 Reflection(const vec3& sourceVector, const vec3& normal);

#endif