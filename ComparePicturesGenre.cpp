//
// Created by Ryan Van Valkenburg on 12/7/21.
//

#include "ComparePicturesGenre.h"

bool ComparePicturesGenre::isLessThan(Pictures &lhs, Pictures &rhs) {
    return lhs.getGenre1() < rhs.getGenre1();
}
