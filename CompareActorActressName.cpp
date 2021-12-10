//
// Created by Ryan Van Valkenburg on 12/7/21.
//

#include "CompareActorActressName.h"

bool CompareActorActressName::isLessThan(ActorActress lhs, ActorActress rhs) {
    return lhs.getName() < rhs.getName();
}
