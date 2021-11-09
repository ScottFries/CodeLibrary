#pragma once

/**
 * Helper to simplify calls to STL algorithms that require a begin and end iterator.
 */
#define ITER_OVER(v) std::begin(v), std::end(v)