#ifndef __wilc_MATH_H__
#define __wilc_MATH_H__

/*!  
*  @file	wilc_Math.h
*  @brief	Math Operations OS wrapper functionality
*  @author	remil
*  @sa		wilc_OSWrapper.h top level OS wrapper file
*  @date	2 Nov 2010
*  @version	1.0
*/

#ifndef CONFIG_wilc_MATH_OPERATIONS_FEATURE
#error the feature CONFIG_wilc_MATH_OPS_FEATURE must be supported to include this file
#endif



/**
*  @brief 		Returns the arc cosine of x in radians.
*  @details 	Returns the arc cosine of x in radians.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The value x must be within the range of -1 to +1 (inclusive).
				The returned value is in the range of 0 to pi (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_acos(wilc_Double x);

/**
*  @brief 		Returns the arc sine of x in radians.
*  @details 	Returns the arc sine of x in radians.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The value x must be within the range of -1 to +1 (inclusive).
				The returned value is in the range of 0 to pi (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_asin(wilc_Double x);

/**
*  @brief 		Returns the arc tangent of x in radians.
*  @details 	Returns the arc tangent of x in radians.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The value of x has no range. 
				The returned value is in the range of -p/2 to +p/2 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_atan(wilc_Double x);

/**
*  @brief 		Returns the arc tangent in radians
*  @details 	Returns the arc tangent in radians of y/x based on the
				signs of both values to determine the correct quadrant.
*  @param[in] 	wilc_Double x
*  @param[in] 	wilc_Double y
*  @return 		wilc_Double 
*  @note 		Both y and x cannot be zero.
				The returned value is in the range of -p/2 to +p/2 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_atan2(wilc_Double y, wilc_Double x);


/**
*  @brief 		Returns the cosine of a radian angle x.
*  @details 	Returns the cosine of a radian angle x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The value of x has no range.
				The returned value is in the range of -1 to +1 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_cos(wilc_Double x);


/**
*  @brief 		Returns the hyperbolic cosine of x.
*  @details 	Returns the hyperbolic cosine of x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_cosh(wilc_Double x);


/**
*  @brief 		Returns the sine of a radian angle x.
*  @details 	Returns the sine of a radian angle x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The value of x has no range.
				The returned value is in the range of -1 to +1 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_sin(wilc_Double x);


/**
*  @brief 		Returns the hyperbolic sine of x.
*  @details 	Returns the hyperbolic sine of x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_sinh(wilc_Double x);
/**
*  @brief 		Returns the tangent of a radian angle x.
*  @details 	Returns the tangent of a radian angle x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_tan(wilc_Double x);

/**
*  @brief 		Returns the hyperbolic tangent of x.
*  @details 	Returns the hyperbolic tangent of x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The value of x has no range.
				The returned value is in the range of -1 to +1 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_tanh(wilc_Double x);


/**
*  @brief 		Returns the value of e raised to the xth power.
*  @details 	Returns the value of e raised to the xth power.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_exp(wilc_Double x);

/**
*  @brief 		The returned value is the mantissa and the integer pointed to by exponent is the exponent.
*  @details 	The returned value is the mantissa and the integer pointed to by exponent is the exponent.
				The resultant value is x=mantissa * 2^exponent.
*  @param[in] 	wilc_Double x
*  @param[out] 	wilc_Sint32* exponent
*  @return 		wilc_Double 
*  @note 		The mantissa is in the range of .5 (inclusive) to 1 (exclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_frexp(wilc_Double x, wilc_Sint32* exponent);



/**
*  @brief 		Returns x multiplied by 2 raised to the power of exponent.
*  @details 	Returns x multiplied by 2 raised to the power of exponent.
				x*2^exponent
*  @param[in] 	wilc_Double x
*  @param[out] 	wilc_Sint32 exponent
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_ldexp(wilc_Double x, wilc_Sint32 exponent);


/**
*  @brief 		Returns the natural logarithm (base-e logarithm) of x.
*  @details 	Returns the natural logarithm (base-e logarithm) of x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_log(wilc_Double x);


/**
*  @brief 		Returns the common logarithm (base-10 logarithm) of x.
*  @details 	Returns the common logarithm (base-10 logarithm) of x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_log10(wilc_Double x);


/**
*  @brief 		Breaks the floating-point number x into integer and fraction components.
*  @details 	Breaks the floating-point number x into integer and fraction components.
				The returned value is the fraction component (part after the decimal),
				and sets integer to the integer component.

*  @param[in] 	wilc_Double x
*  @param[out] 	wilc_Double* dInteger
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_modf(wilc_Double x,wilc_Double* dInteger);



/**
*  @brief 		Returns x raised to the power of y.
*  @details 	Returns x raised to the power of y.
*  @param[in] 	wilc_Double x
*  @param[in] 	wilc_Double y
*  @return 		wilc_Double 
*  @note 		x cannot be negative if y is a fractional value.
				x cannot be zero if y is less than or equal to zero.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_pow(wilc_Double x,wilc_Double y);



/**
*  @brief 		Returns the square root of x.
*  @details 	Returns the square root of x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		The argument cannot be negative. The returned value is always positive.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_sqrt(wilc_Double x);

/**
*  @brief 		Returns the smallest integer value greater than or equal to x.
*  @details 	Returns the smallest integer value greater than or equal to x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_ceil(wilc_Double x);

/**
*  @brief 		Returns the absolute value of x
*  @details 	Returns the absolute value of x 
				(a negative value becomes positive, positive value is unchanged).
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument.
				The return value is always positive.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_fabs(wilc_Double x);

/**
*  @brief 		Returns the largest integer value less than or equal to x.
*  @details 	Returns the largest integer value less than or equal to x.
*  @param[in] 	wilc_Double x
*  @return 		wilc_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_floor(wilc_Double x);

/**
*  @brief 		Returns the remainder of x divided by y.
*  @details 	Returns the remainder of x divided by y.
*  @param[in] 	wilc_Double x
*  @param[in] 	wilc_Double y
*  @return 		wilc_Double 
*  @note 		There is no range limit on the return value. 
				If y is zero, then either a range error will occur or the function 
				will return zero (implementation-defined).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Double wilc_fmod(wilc_Double x,wilc_Double y);


/**
*  @brief 		
*  @details 	Returns the absolute value of x. 
				Note that in two's compliment that the most maximum number cannot be 
				represented as a positive number. The result in this case is undefined.
				The absolute value is returned.
*  @param[in] 	wilc_Sint32 x
*  @return 		wilc_Sint32 
*  @note 		
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Sint32 wilc_abs(wilc_Sint32 x);




/**
*  @brief 		
*  @details 	Returns a pseudo-random number in the range of 0 to RAND_MAX.
*  @return 		wilc_Sint32 
*  @note 		
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
wilc_Sint32 wilc_rand();


/**
*  @brief 		
*  @details 	This function seeds the random number generator used by the function rand.
				Seeding srand with the same seed will cause rand to return the same sequence
				of pseudo-random numbers.
				If srand is not called, wilc_rand acts as if wilc_srand(1) has been called.

*  @param[in] 	wilc_Uint32 seed
*  @note 		No value is returned.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
void wilc_srand(wilc_Uint32 seed);



#endif
