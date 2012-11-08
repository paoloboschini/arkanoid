/*
 *  ErrorException.h
 *
 *  Created by Paolo Boschini on 12/8/10.
 *
 */

#ifndef ERROREXCEPTION_H
#define ERROREXCEPTION_H

#include <string>

namespace enginespace {

  struct ErrorException {
    std::string message;
    ErrorException(std::string m):message(m) {}
  };
}
#endif