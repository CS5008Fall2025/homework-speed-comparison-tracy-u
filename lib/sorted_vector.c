/**
 * Contains functions for the sorted vector struct
 *
 * @author: STUDENT ADD YOUR NAME
 * @class: CS 5008
 * @term: UPDATE WITH CURRENT SEMESTER
**/

#include "vector.h"
#include "movie.h"


/**
 * adds a movie to the sorted vector.
 * 
 * Based on the movie (compare_movies), it will find the correct index
 * using a linear search.
 * 
 * The moment it finds that the movie to add is greater than the
 * current movie, it will insert it at that next index calling vector_insert.
 * 
 * 
 * @param vector the vector to add the movie to
 * @param movie the movie to add
*/
void add_to_sorted_vector(SortedMovieVector * vector, Movie * movie) {
    int i = 0;
    if (vector->size != 0) {
        while ((i < vector->size) && (compare_movies(vector->movies[i], movie) <= 0)) {
            i++;
        }
    }
    vector_insert(vector, movie, i);
}


Movie* movie_binary_search(SortedMovieVector * vector, const char * title, int low, int high) {
    int mid = low + (high - low) / 2;
    if (high >= low) {
        if (strcasecmp(vector->movies[mid]->title, title) == 0) {
            return vector->movies[mid];
        }
        if (strcasecmp(vector->movies[mid]->title, title) > 0) {
            return movie_binary_search(vector, title, low, mid - 1);
        }
        if (strcasecmp(vector->movies[mid]->title, title) < 0) {
            return movie_binary_search(vector, title, mid + 1, high);
        }
    }
    return NULL;
}

/**
 * Finds a movie in the sorted vector based on the title only of the movie.
 *
 * strcasecmp is used to compare the titles, so the search is case insensitive.
 *
 * For example: int cmp = strcasecmp(title, movie->title);
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one. 
 *
 * @param vector the vector to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
 */
Movie * find_in_sorted_vector(SortedMovieVector * vector, const char * title) {
    if (vector->size == 0) {
        return NULL;
    }
    return movie_binary_search(vector, title, 0, vector->size - 1);
}

Movie* movie_binary_remove(SortedMovieVector * vector, const char * title, int low, int high) {
    int mid = low + (high - low) / 2;
    if (high >= low) {
        if (strcasecmp(vector->movies[mid]->title, title) == 0) {
            return vector_remove(vector, mid);
        }
        if (strcasecmp(vector->movies[mid]->title, title) > 0) {
            return movie_binary_remove(vector, title, low, mid - 1);
        }
        if (strcasecmp(vector->movies[mid]->title, title) < 0) {
            return movie_binary_remove(vector, title, mid + 1, high);
        }
    }
    return NULL;
}


/**
 * Checks if the sorted vector contains a movie with the given title.
 *
 * Very similar to find_in_sorted_vector, but instead of just finding
 * the movie will call vector_remove(vector, index) to remove the movie
 * returning the resulted removed movie.
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one.
 *
 * @param vector the vector to check
 * @param title the title to check for
 * @return the movie removed, NULL otherwise
 */
Movie* sorted_vector_remove(SortedMovieVector *vector, const char *title){
    // STUDENT TODO: implement this function
    if (vector->size == 0) {
        return NULL;
    }
    return movie_binary_remove(vector, title, 0, vector->size - 1);
}
