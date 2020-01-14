/** \file SearchAlgorithms.h
 * Library for one-dimensional, two-dimensional and three-dimensional array search algorithms.
 */

/*
 *  SearchAlgorithms.h
 *
 *  Created by Walisson Pereira de Jesus on 05/12/19.
 *  Instituto de Informatica - UFG
 *
 */

/*!
 * \author Walisson Pereira de Jesus
 * \version 1.0
 * \date 2019-06-12
 */ 

/** \file SearchAlgorithms.h
 * Code library for matrix search algorithms.
 */

#ifndef SearchAlgorithms_hpp
#define SearchAlgorithms_hpp

#include <algorithm>
#include <vector>
#include <math.h>

//! One-dimensional search functions.

/*!
 * \brief Function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool linear_search(ForwardIt first, ForwardIt last, const T& value){
    for( ; first != last; ++first){
        if( *first == value)
            return true;
    }
    return false;
}

/*!
 * \brief Linear search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool jump_search(ForwardIt first, ForwardIt last, const T& value){
    int i, n, step, j;
    i = 0;
    n = last - first;
    step = std::sqrt(n);
    j = step;
    while(j < n){
        if( value == first[j]){
            return true;
        }
        else if(value > first[j]){
            i = j;
            j += step;
        }else
            break;
    }
    j = j<n? j : n-1;
    while( i <= j){
        if(value == first[i])
            return true;
        else
            ++i;
    }
    return false;
}


/*!
 * \brief Interpolation search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool interpolation_search(ForwardIt first, ForwardIt last, const T& value){
    int i, n, j;
    i = 0;
    n = last - first;
    j = n-1;
    while(i <= j && first[i] != first[j] && value >= first[i] && value <= first[j]){
        int p = i + (((double)(j-i) / (first[j]-first[i]))*(value - first[i]));
        if( value == first[p]){
            return true;
        }
        else if(value < first[p])
            j = p-1;
        else
            i = p+1;
    }
    if(i < n-1 && value == first[i])
    	return true;
    return false;
}

/*!
 * \brief Exponential search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool exponential_search(ForwardIt first, ForwardIt last, const T& value){
    int n;
    n = last - first;
    if(first[0] == value) 
        return true;
    int i = 1;
    while(i < n && value > first[i]){
        i *= 2;
    }
    return std::binary_search( first+(i/2+1), first + ((i < n)? i+1 : n), value);
}


/*!
 * \brief Fiboncci search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool fibonaccian_search(ForwardIt first, ForwardIt last, const T& value){
    int f, f1, f2, n, offset, p;
    n = last - first;
    f2 = 0;
    f1 = 1;
    f = f1 + f2;
    while(f < n){
        f2 = f1;
        f1 = f;
        f = f1 + f2;
    }
    offset = -1;
    while(f > 1){
        p =  (offset + f2) < n-1? offset+f2 : n-1;
        if(value > first[p]){
            f = f1;
            f1 = f2;
            f2 = f - f1;
            offset = p;
        }else if(value < first[p]){
            f = f2;
            f1 -= f2;
            f2 = f - f1;
        }else{
            return true;
        }
    }
    
    if(f > 0 && first[offset+1] == value){
        return true;
    }
    return false;
}


//! Two-dimensional search functions.




/*!
 * \brief Saddleback search function.
 * \param first iterator to start of array.
 * \param  j1  leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool saddleback_search(ForwardIt first, int i1, int j1, int in, int jn, const T& value){
    int  i, j;
    i = i1;
    j = jn;
    while( i <= in && j >= j1){
        if( first[i][j] == value){
            return true;
        }
        if( first[i][j] > value)
            j--;
        else
            i++;
    }
    return false;
}


/*!
 * \brief Saddleback search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool saddleback_search(ForwardIt first, ForwardIt last,  const T& value){
   int jn = first[0].size()-1;
   int in = last - first - 1;
   return saddleback_search(first, 0, 0, in, jn, value);
}

/*!
 * \brief Binary search function.
 * \param first iterator to start of array.
 * \param  j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool binary_search(ForwardIt first, int i1, int j1, int in, int jn, const T& value){
    int lower, high;
    if((in-i1+1) < 4){
        for( int i = i1; i <= in ; i++){
            if(std::binary_search(first[i].begin(), first[i].end(), value)){
                return true;
            }
        }
    }else{
        for( int i = j1; i <= jn; i++){
            lower = i1;
            high = in;
            while( lower <= high){
                int mid = (lower+high)>>1;
                if( value == first[mid][i])
                    return true;
                else if( value < first[mid][i])
                    high = mid-1;
                else
                    lower = mid+1;
            }
        }
    }
    return false;
}

/*!
 * \brief Shen search function.
 * \param first iterator to start of array.
 * \param  j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool shen_search(ForwardIt first, int i1,int j1, int in, int jn, const T& value){
    if((in - i1+1) < 4 || (jn-j1+1) < 4){
        return binary_search(first, i1,j1, in, jn, value);
    }
    int i = (i1+in)>>1;
    if(value == first[i][j1])
    	return true;
    else{
    	if( value < first[i][j1])
        	return shen_search(first, i1, j1, i-1, jn, value);
        else{
	        if( value > first[i][jn])
	            return shen_search(first, i+1, j1, in, jn, value);
	        else{
	            int j;
	            j = lower_bound(first[i].begin() + j1, first[i].begin()+jn+1, value) - first[i].begin();
	            if( first[i][j] != value)
	                return shen_search(first, i+1, j1, in, j, value) || shen_search(first, i1, j+1,  i-1, jn, value);
	            else
	                return true;
	        }
	    }
    }
}


/*!
 * \brief Shen search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool shen_search(ForwardIt first, ForwardIt last, const T& value){
	int j = (int)first[0].size()-1;
	int in = last - first - 1;
    return shen_search(first, 0, 0, in, j, value);
}


/* Three-dimensional search functions */

/*
	 	      ___v*2___
	  	 	 /|       /|
	 		/ w1	u1 |
(0,0,0)	   /__|_____/__|
	 	   |  /     |  / (n, n, n)
	 	   | u2    w2 /
	 	   |/__v1___|/
 
 vector u1 = (i1 j2, )
 binary search in u1, w1, u2, w2, v1 end v2.
 saddleback face in the 6 faces:
 u1 and v2
 v1 and w2
 u1 and w2
 w1 and u2
 v1 and u2
 w1 and v2
 */



/*!
 * \brief Saddleback search function for array ij face.
 * \param first iterator to start of array.
 * \param i1 leftmost i position of the array.
 * \param in rightmost i position of the array.
 * \param j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param k array k postition.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool saddleback_ij(ForwardIt first, int i1, int in, int j1, int jn, int k, const T& value){
    int x, y;
    x = i1;
    y = jn;
    while(x <= in && y >= j1){
        if(first[x][y][k] == value)
            return true;
        if(first[x][y][k] > value)
            y--;
        else
            x++;
    }
    return false;
}


/*!
 * \brief Saddleback search function for array ik face.
 * \param first iterator to start of array.
 * \param i1 leftmost i position of the array.
 * \param in rightmost i position of the array.
 * \param j array j postition.
 * \param k1 leftmost k position of the array.
 * \param kn rightmost k position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool saddleback_ik(ForwardIt first, int i1, int in, int j, int k1, int kn, const T& value){
    int x, z;
    x = in;
    z = k1;
    while( x >= i1 && z <= kn){
        if(first[x][j][z] == value)
            return true;
        if(first[x][j][z] > value)
            x--;
        else
            z++;
    }
    return false;
}

/*!
 * \brief Saddleback search function for array ik face.
 * \param first iterator to start of array.
 * \param i array i position.
 * \param j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param k1 leftmost k position of the array.
 * \param k2 rightmost k position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool saddleback_jk( ForwardIt first,  int i, int j1, int jn, int k1, int k2, const T& value){
    int y, z;
    y = jn;
    z = k1;
    while(y >= j1 && z <= k2){
        if(first[i][y][z] == value)
            return true;
        if(first[i][y][z] > value)
            y--;
        else
            z++;
    }
    return false;
}


/*!
 * \brief Binary search function in subvetor i.
 * \param first iterator to start of array.
 * \param i1 leftmost i position of the array.
 * \param in rightmost i position of the array.
 * \param j array j position.
 * \param k array k position.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
int binary_search_i(ForwardIt first, int i1, int in, int j, int k, const T& value){
    int lo, hi;
    lo = i1;
    hi = in;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if( first[mid][j][k] < value)
            lo = mid+1;
        else if( first[mid][j][k] > value)
            hi = mid-1;
        else
            return mid;
    }
    return hi;
}



/*!
 * \brief Binary search function in subvetor j
 * \param first iterator to start of array.
 * \param i array i position. 
 * \param j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param k array k position.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
int binary_search_j(ForwardIt first, int i, int j1, int jn, int k, const T& value){
    int lo, hi; 
    lo = j1;
    hi = jn;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if( first[i][mid][k] < value)
            lo = mid+1;
        else if( first[i][mid][k] > value)
            hi = mid-1;
        else
            return mid;
    }
    return hi;
}



/*!
 * \brief Binary search function in subvetor k
 * \param i array i position.
 * \param j array j position.
 * \param k1 leftmost k position of the array.
 * \param kn rightmost k position of the array.
 * \param  value is the search key.
 */

template<class ForwardIt, class T>
int binary_search_k(ForwardIt first, int i, int j, int k1, int kn, const T& value){
    int lo, hi;
    lo = k1;
    hi = kn;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if( first[i][j][mid] < value)
            lo = mid+1;
        else if( first[i][j][mid] > value)
            hi = mid-1;
        else
            return mid;
    }
    return hi;
}

/*!
 * \brief Linial and Saks search function.
 * \param first iterator to start of array.
 * \param i1 leftmost i position of the array.
 * \param in rightmost i position of the array.
 * \param j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param k1 leftmost k position of the array.
 * \param kn rightmost k position of the array.
 * \param  value is the search key.
 */

template<class ForwardIt, class T>
bool linialsaks_search(ForwardIt first, int i1, int j1, int k1, int in, int jn, int kn, const T& value){
    if(i1 > in || j1 > jn || k1 > kn)
        return false;
    if(i1 == in ||j1 == jn || k1 == kn){
    	if(i1 == in && j1 == jn && k1 == kn){
        	if(value == first[i1][j1][k1])
            	return true;
        	else
            	return false;
    	}
    	else{
    		if(i1 == in){
    			return saddleback_jk(first, i1, j1, jn, k1, kn, value);
    		}
    		else if(j1 == jn){
    			return saddleback_ik(first, i1, in, j1, k1, kn, value);
    		}
    		else
    			return saddleback_ij(first, i1, in, j1, jn, k1, value);
    	}
    }

    int u1, u2, w1, w2, v1, v2;

    /* Binary search in subarray u1. Variable u1 is the position returned in binary search. */
    u1 = binary_search_k(first, i1, jn, k1, kn, value);
    if(u1>= 0 && first[i1][jn][u1] == value)
        return true;
    /* Binary search in subarray w1. Variable w1 is the position returned in binary search.*/
    w1 = binary_search_i(first, i1, in, j1, kn, value);
    if(w1 >= 0 && first[w1][j1][kn] == value)
        return true;
    
    /* Binary search in subarray u2. Variable u2 is the position returned in binary search.*/
    u2 = binary_search_k(first, in, j1, k1, kn, value);
    if(u2 >= 0 && first[in][j1][u2] == value)
        return true;
    
    /* Binary search in subarray w2. Variable w2 is the position returned in binary search.*/
    w2 = binary_search_i(first, i1, in, jn, k1, value);
    if(w2 >= 0 && first[w2][jn][k1] == value)
        return true;
    
    /* Binary search in subarray v1. Variable v1 is the position returned in binary search.*/
    v1 = binary_search_j(first, in, j1, jn, k1, value);
    if(v1 >= 0 && first[in][v1][k1] == value)
        return true;
    
    /* Binary search in subarray v2. Variable v2 is the position returned in binary search.*/
    v2 = binary_search_j(first, i1, j1, jn, kn, value);
    if(v2 >= 0 && first[i1][v2][kn] == value)
        return true;
    
    /* saddleback v2 u1...   (i1, v2+1, u1+1) to (i1, jn, kn)  */
    if(v2+1 <= jn && u1+1 <= kn && saddleback_jk(first, i1, v2+1, jn, u1+1, kn, value) == true)
        return true;
    
    /* saddleback w2 v1...   (w2+1, v1+1, k1) to (in, jn, k1) */
    if(w2+1 <= in && v1+1<= jn && saddleback_ij(first, w2+1, in, v1+1, jn, k1, value)==true)
        return true;
    
    /* saddleback u1 w2...   (i1, jn, k1) to (w2, jn, u1) */
    if(w2 >= 0 && u1 >= 0 && saddleback_ik(first, i1, w2, jn, k1, u1, value)==true)
        return true;
    
    /* saddleback u2 w1 ...  (w1+1, j1, u2+1) to (in, j1, kn)*/
    if(w1+1 <= in && u2+1 <= kn && saddleback_ik(first, w1+1, in, j1, u2+1, kn, value)==true)
        return true;
    
    /* saddleback u2 v1...   (in, j1, k1) to (in, v1, u2)*/
    if(v1 >= 0 && u2 >= 0 && saddleback_jk(first, in, j1, v1, k1, u2, value) == true)
        return true;
    
    /* saddleback w1 v2...   (i1, j1, kn) to (w1, v2, kn)*/
    if(w1 >= 0 && v2 >= 0 && saddleback_ij(first, i1, w1, j1, v2, kn, value) == true)
        return true;
    
    return linialsaks_search(first, i1+1, j1+1, k1+1, in-1, jn-1, kn-1, value);
}


/*!
 * \brief Linial and Saks search function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool linialsaks_search(ForwardIt first, ForwardIt last, const T& value){
    int in, jn, kn;
    in = (last - first) -1;
    jn = first[0].size() - 1;
    kn = first[0][0].size() - 1;
    return linialsaks_search(first, 0, 0, 0, in, jn, kn, value);
}


/*
 * 
 ( N,*0,P) 		_______________
 		      /|    		  /|  (M, N, P)
 			 / |	         / |
 (M,0,0)    /__|____________/__|
 			|  |            |  | 
 			|  |____________|__| (0,N,P)
 			|  /            |  / 
 			| /             | /
 (0,0,0)	|/______________|/ (0,N,0)
 
 
 */

/*!
 * \brief MAHL_e function.
 * \param first iterator to start of array.
 * \param i1 leftmost i position of the array.
 * \param in rightmost i position of the array.
 * \param j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param k1 leftmost k position of the array.
 * \param kn rightmost k position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool MAHL_e(ForwardIt first, int i1, int j1, int k1, int im, int jn, int kp, const T& value){
    if(i1 > im || j1 > jn || k1 > kp)
        return false;
    int diff_i = im - i1 + 1;
    int diff_j = jn - j1 + 1;
    int diff_k = kp - k1 + 1;
    /*If dimension i is less than 3 and smaller than dimensions j and k, apply the saddleback algorithm to it. */
    if(diff_i <= 3 && diff_i <= diff_j && diff_i <= diff_k){
        for( int i = i1; i <= im; ++i)
            if(saddleback_jk(first, i, j1, jn, k1, kp, value))
                return true;
            return false;
    }
    /*If dimension j is less than 3 and smaller than dimensions i and k, apply the saddleback algorithm to it.*/
    if(diff_j <= 3 && diff_j <= diff_i && diff_j <= diff_k){
        for( int j = j1; j <= jn; ++j)
            if(saddleback_ik(first, i1, im, j, k1, kp, value))
                return true;
            return false;
    }
    /*If dimension k is less than 3 and smaller than dimensions i and j, apply the saddleback algorithm to it.*/
    if(diff_k <= 3 && diff_k <= diff_i && diff_k <= diff_j){
        for( int k = k1; k <= kp; ++k)
            if(saddleback_ij(first, i1, im, j1, jn, k, value))
                return true;
            return false;
    }
    
    /*If dimension i is larger, apply the algorithm to it.*/
    if(diff_i >= diff_j && diff_i >= diff_k){
        int mid_j = (j1 + jn) >> 1; /* floor of N/2 */
        int mid_k = (k1 + kp) >> 1; /*  floor of P/2 */
        
        int index_i = binary_search_i(first, i1, im, mid_j, mid_k, value);
        if( index_i >= 0 && first[index_i][mid_j][mid_k] == value)
            return true;
        
        return MAHL_e(first, index_i+1, j1, k1, im, mid_j, kp, value) ||
        MAHL_e(first, i1, j1, mid_k, index_i, jn, kp, value) ||
        MAHL_e(first, i1, mid_j+1, k1, im, jn, mid_k-1, value);
    }
    /*If dimension j is larger, apply the algorithm to it.*/
    else if(diff_j >= diff_i && diff_j >= diff_k){
        int mid_i = (i1 + im) >> 1; /* floor of M/2 */
        int mid_k = (k1 + kp) >> 1; /*  floor of P/2 */
        
        int index_j = binary_search_j(first, mid_i, j1, jn, mid_k, value);
        if(index_j >= 0 && first[mid_i][index_j][mid_k] == value)
            return true;
        return MAHL_e(first, mid_i, j1, k1, im, index_j, kp, value) ||
        MAHL_e(first, i1, j1, mid_k, mid_i-1, jn, kp, value) || 
        MAHL_e(first, i1, index_j+1, k1, im, jn, mid_k-1, value);
    }
    /*If dimension k is larger, apply the algorithm to it.*/
    else{
        int mid_i = (i1 + im) >> 1; /* floor of M/2 */
        int mid_j = (j1 + jn) >> 1; /* foor of N/2 */
        
        int index_k = binary_search_k(first, mid_i, mid_j, k1, kp, value);
        if(index_k >= 0 && first[mid_i][mid_j][index_k] == value)
            return true;
        return MAHL_e(first, mid_i, j1, k1, im, mid_j, kp, value) ||
        MAHL_e(first, i1, j1, index_k+1, mid_i-1, jn, kp, value) ||
        MAHL_e(first, i1, mid_j+1, k1, im, jn, index_k, value);
    }
}

/*!
 * \brief MAHL_e function.
 * \param first iterator to start of array.
 * \param last iterator to end of array.
 * \param i1 leftmost i position of the array.
 * \param in rightmost i position of the array.
 * \param j1 leftmost j position of the array.
 * \param jn rightmost j position of the array.
 * \param k1 leftmost k position of the array.
 * \param kn rightmost k position of the array.
 * \param  value is the search key.
 */
template<class ForwardIt, class T>
bool MAHL_e(ForwardIt first, ForwardIt last, const T& value){
    int im, jn, kp;
    im = (last - first) - 1;
    jn = first[0].size() - 1;
    kp = first[0][0].size() - 1;
    return MAHL_e(first, 0, 0, 0, im, jn, kp, value);
}

#endif