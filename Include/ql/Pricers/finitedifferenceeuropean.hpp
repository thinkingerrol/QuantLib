
/*
 * Copyright (C) 2000-2001 QuantLib Group
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 * The license is also available at http://quantlib.sourceforge.net/LICENSE.TXT
 *
 * The members of the QuantLib Group are listed in the Authors.txt file, also
 * available at http://quantlib.sourceforge.net/Authors.txt
*/

/*! \file finitedifferenceeuropean.hpp
    \brief Example of european option calculated using finite differences

    $Id$
*/

// $Source$
// $Log$
// Revision 1.5  2001/06/22 16:38:15  lballabio
// Improved documentation
//
// Revision 1.4  2001/06/05 09:35:13  lballabio
// Updated docs to use Doxygen 1.2.8
//
// Revision 1.3  2001/05/24 15:38:08  nando
// smoothing #include xx.hpp and cutting old Log messages
//

#ifndef quantlib_pricers_finite_difference_european_option_h
#define quantlib_pricers_finite_difference_european_option_h

#include "ql/Pricers/bsmnumericaloption.hpp"
#include "ql/FiniteDifferences/standardfdmodel.hpp"

namespace QuantLib {

    namespace Pricers {

        class FiniteDifferenceEuropean : public BSMNumericalOption {
          public:
            FiniteDifferenceEuropean(Type type,
                 double underlying, double strike,
                 Rate dividendYield, Rate riskFreeRate,
                 Time residualTime, double volatility,
                 int timeSteps = 200, int gridPoints = 800);
           	Array getPrices() const;
            Handle<BSMOption> clone() const{
                return Handle<BSMOption>(new FiniteDifferenceEuropean(*this));
            }
          protected:
            void calculate() const;
          private:
            int timeSteps_;
            mutable Array euroPrices_;
        };

        // inline definitions
        
        inline Array  FiniteDifferenceEuropean::getPrices() const{
            value();
            return euroPrices_;
        }

    }

}

#endif
