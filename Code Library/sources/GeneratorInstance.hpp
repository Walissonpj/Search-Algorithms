/*!
 * \author Walisson Pereira de Jesus
 * \version 1.0
 * \date 2019-06-12
 */ 

/** \file GeneratorInstance.h
 * Library for instance generators sorted by dimension. Instances are generated using an increasing, decreasing or normal uniform distribution.
 */


/*
 *  GeneratorInstance.h
 *
 *  Created by Walisson Pereira de Jesus on 05/12/19.
 *  Instituto de Informatica - UFG
 *
 */

#ifndef GeneratorInstance_hpp
#define GeneratorInstance_hpp

#include <chrono>
#include <random>
#include <vector>
#include <math.h>

/*!
 * \brief Function to generate an increasing uniform distribution.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearIncreasingDistribution(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int N = (last - first); /* Array size.*/
    offset = (max_value - min_value+1.) /(T)N; /*The values are generated within this range and added to the previous element of the sequence.*/
    for(int i = 0; i < N; ++i){
        if(i == 0)
            first[i] = (T)(offset * std::sqrt(dis(gen))) + min_value;
        else
            first[i] = (T)(offset * std::sqrt(dis(gen))) + first[i-1];
    }
}
/*!
 * \brief Function to generate a decreasing uniform distribution.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearDecreasingDistribution(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int N = (last - first); /* Array size.*/
    offset = (max_value - min_value+1.)  / (T)N; /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < N; ++i){
        if( i == 0)
            first[i] = (T)((offset) * (1. - std::sqrt(1.-dis(gen)))) + min_value;
        else
            first[i] = (T)((offset) * (1. - std::sqrt(1.-dis(gen)))) + first[i-1];
    }
}
/*!
 * \brief Function to generate a normal uniform distribution.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearNormalDistribution(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int N = (last - first); /* Array size.*/
    offset = (max_value - min_value+1.)  / (T)N; /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < N; ++i){
        if(i == 0)
            first[i] = (T)((offset) * dis(gen)) + min_value;
        else
            first[i] = (T)((offset) * dis(gen)) + first[i-1];
    }
}


//! Functions for generating a uniform distribution for a two-dimensional array.

/*!
 * \brief Function to generate a growing uniform distribution for a two-dimensional array.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearIncreasingDistribution_2D(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int M = (last - first);  /* Size of the first dimension.*/
    int N = (first[0].size()); /* Size of the second dimension.*/
    offset = (max_value - min_value+1.) /(T)(M+N); /*The values are generated within this range and added to the previous element of the sequence.*/
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if( i == 0 || j == 0){
                if( i == 0 && j == 0)
                    first[i][j] = (T)(offset * std::sqrt(dis(gen))) + min_value;
                else if( i == 0)
                    first[i][j] = (T)(offset * std::sqrt(dis(gen))) + first[i][j-1];
                else
                    first[i][j] = (T)(offset * std::sqrt(dis(gen))) + first[i-1][j];
            }else
                first[i][j] = (T)(offset * std::sqrt(dis(gen))) + std::max(first[i-1][j], first[i][j-1]);
        }
    }
}
/*!
 * \brief Function to generate a decreasing uniform distribution for a two-dimensional array.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearDecreasingDistribution_2D(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int M = (last - first); /* Size of the first dimension.*/
    int N = (first[0].size()); /* Size of the second dimension.*/
    offset = (max_value - min_value+1.)  / (T)(M+N); /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < M; ++i){
        for( int j=0; j < N; ++j){
            if( i == 0 || j == 0){
                if( i == 0 && j == 0)
                    first[i][j] = (T)((offset)*(1. - std::sqrt(1.-dis(gen)))) + min_value;
                else if( i == 0)
                    first[i][j] = (T)((offset)*(1. - std::sqrt(1.-dis(gen)))) + first[i][j-1];
                else
                    first[i][j] = (T)((offset)*(1. - std::sqrt(1.-dis(gen)))) + first[i-1][j];
            }else
                first[i][j] = (T)((offset)*(1. - std::sqrt(1.-dis(gen)))) + std::max(first[i-1][j], first[i][j-1]);
        }
    }
}

/*!
 * \brief Function to generate a normal uniform distribution for a two-dimensional array.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearNormalDistribution_2D(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int M = (last - first); /* Size of the first dimension.*/
    int N = (first[0].size()); /* Size of the second dimension.*/
    offset = (max_value - min_value+1.) / (T)(M+N); /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < M; ++i){
        for( int j = 0; j < N; ++j){
            if( i == 0 || j == 0){
                if( i == 0 && j == 0)
                    first[i][j] = (T)(offset * dis(gen)) + min_value;
                else if( i == 0)
                    first[i][j] = (T)(offset * dis(gen)) + first[i][j-1];
                else
                    first[i][j] = (T)(offset * dis(gen)) + first[i-1][j];
            }else
                first[i][j] = (T)(offset * dis(gen)) + std::max(first[i-1][j], first[i][j-1]);
        }
    }
}


//! Functions for generating a uniform distribution for a three-dimensional array.

/*!
 * \brief Function to generate a growing uniform distribution for a three-dimensional array.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearIncreasingDistribution_3D(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int M = (last - first); /* Size of the first dimension.*/
    int N = (first[0].size()); /* Size of the second dimension.*/
    int P =  (first[0][0].size()); /* Size of the third dimension.*/
    offset = (max_value - min_value+1.) /(T)(M+N+P); /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < M; ++i){
        for( int j = 0; j < N; ++j){
            for( int k = 0; k < P; ++k){
                if( i == 0 || j == 0 || k==0){
                    if( i == 0 && j == 0 && k==0)
                        first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + min_value;
                    else if( i == 0){
                        if( k == 0)
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + first[i][j-1][k];
                        else if(j==0)
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + first[i][j][k-1];
                        else
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + std::max(first[i][j-1][k], first[i][j][k-1]);
                    }
                    else if(j == 0){
                        if( i == 0)
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + first[i][j][k-1];
                        else if(k==0)
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + first[i-1][j][k];
                        else
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + std::max(first[i-1][j][k], first[i][j][k-1]);
                    }else{
                        if( i == 0)
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + first[i][j-1][k];
                        else if(j==0)
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + first[i-1][j][k];
                        else
                            first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + std::max(first[i-1][j][k], first[i][j-1][k]);
                    }
                }else
                    first[i][j][k] = (T)(offset * std::sqrt(dis(gen))) + std::max(first[i-1][j][k], std::max(first[i][j-1][k], first[i][j][k-1]));
            }
        }
    }
}

/*!
 * \brief Function to generate a decreasing uniform distribution for a three-dimensional array.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearDecreasingDistribution_3D(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int M = (last - first); /* Size of the first dimension.*/
    int N = (first[0].size()); /* Size of the second dimension.*/
    int P =  (first[0][0].size()); /* Size of the third dimension.*/
    offset = (max_value - min_value+1.)  / (T)(M+N+P); /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < M; ++i){
        for( int j = 0; j < N; ++j){
            for( int k = 0; k < P; ++k){
                if( i == 0 || j == 0 || k==0){
                    if( i == 0 && j == 0 && k==0)
                        first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + min_value;
                    else if( i == 0){
                        if( k == 0)
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + first[i][j-1][k];
                        else if(j==0)
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + first[i][j][k-1];
                        else
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + std::max(first[i][j-1][k], first[i][j][k-1]);
                    }
                    else if(j == 0){
                        if( i == 0)
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + first[i][j][k-1];
                        else if(k==0)
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + first[i-1][j][k];
                        else
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + std::max(first[i-1][j][k], first[i][j][k-1]);
                    }else{
                        if( i == 0)
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + first[i][j-1][k];
                        else if(j==0)
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + first[i-1][j][k];
                        else
                            first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + std::max(first[i-1][j][k], first[i][j-1][k]);
                    }
                }else
                    first[i][j][k] = (T)(offset * (1.-std::sqrt(1.-dis(gen)))) + std::max(first[i-1][j][k], std::max(first[i][j-1][k], first[i][j][k-1]));
            }
        }
    }
}

/*!
 * \brief Function to generate a normal uniform distribution for a three-dimensional array.
 * \param first iterator to start of array.
 * \param last iterator to end of matrix.
 * \param  min_value initial value of sequence.
 * \param max_value maximum sequence offset.
 */
template<class ForwardIt, class T>
void LinearNormalDistribution_3D(ForwardIt first, ForwardIt last, const T& min_value, const T& max_value){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); /* Random seed for distribution.*/
    std::mt19937_64 gen(seed);
    std::uniform_real_distribution<> dis(0.0, 1.0); /* Uniform value generated between 0 and 1.*/
    T offset;
    int M = (last - first); /* Size of the first dimension.*/
    int N = (first[0].size()); /* Size of the second dimension.*/
    int P =  (first[0][0].size()); /* Size of the third dimension.*/
    offset = (max_value - min_value+1.) / (T)(M+N+P); /*The values are generated within this range and added to the previous element of the sequence.*/
    for( int i = 0; i < M; ++i){
        for( int j = 0; j < N; ++j){
            for( int k = 0; k < P; ++k){
                if( i == 0 || j == 0 || k==0){
                    if( i == 0 && j == 0 && k==0)
                        first[i][j][k] = (T)(offset * dis(gen)) + min_value;
                    else if( i == 0){
                        if( k == 0)
                            first[i][j][k] = (T)(offset * dis(gen)) + first[i][j-1][k];
                        else if(j==0)
                            first[i][j][k] = (T)(offset * dis(gen)) + first[i][j][k-1];
                        else
                            first[i][j][k] = (T)(offset * dis(gen)) + std::max(first[i][j-1][k], first[i][j][k-1]);
                    }
                    else if(j == 0){
                        if( i == 0)
                            first[i][j][k] = (T)(offset * dis(gen)) + first[i][j][k-1];
                        else if(k==0)
                            first[i][j][k] = (T)(offset * dis(gen)) + first[i-1][j][k];
                        else
                            first[i][j][k] = (T)(offset * dis(gen)) + std::max(first[i-1][j][k], first[i][j][k-1]);
                    }else{
                        if( i == 0)
                            first[i][j][k] = (T)(offset * dis(gen)) + first[i][j-1][k];
                        else if(j==0)
                            first[i][j][k] = (T)(offset * dis(gen)) + first[i-1][j][k];
                        else
                            first[i][j][k] = (T)(offset * dis(gen)) + std::max(first[i-1][j][k], first[i][j-1][k]);
                    }
                }else
                    first[i][j][k] = (T)(offset * dis(gen)) + std::max(first[i-1][j][k], std::max(first[i][j-1][k], first[i][j][k-1]));
            }
        }
    }
}

#endif