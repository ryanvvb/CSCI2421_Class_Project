//
// Created by Ryan Van Valkenburg on 12/7/21.
//

#include "ComparePicturesName.h"

bool ComparePicturesName::isLessThan(Pictures &lhs, Pictures &rhs) {
    return lhs.getName() < rhs.getName();
}
