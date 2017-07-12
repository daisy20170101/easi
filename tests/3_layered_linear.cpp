/**
 * @file
 * This file is part of SeisSol.
 *
 * @author Carsten Uphoff (c.uphoff AT tum.de, http://www5.in.tum.de/wiki/index.php/Carsten_Uphoff,_M.Sc.)
 *
 * @section LICENSE
 * Copyright (c) 2017, SeisSol Group
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @section DESCRIPTION
 **/

#include "easitest.h"

int main(int argc, char** argv) {
  assert(argc == 2);

  easi::Query query = createQuery<3>({
      {1, { 0.0,  0.0,      0.0}},
      {1, { 0.0,  0.0,  -2000.0}},
      {1, { 0.0,  0.0,  -2100.0}},
      {1, { 0.0,  0.0,  -2500.0}},
      {1, { 0.0,  0.0, -50000.0}},
    });
  
  auto material = elasticModel(argv[1], query);

  assert(equal(material[0].rho,      2600.0));
  assert(equal(material[0].mu,      1.04e10));
  assert(equal(material[0].lambda,  2.08e10));

  assert(equal(material[1].rho,      2700.0));
  assert(equal(material[1].mu,      3.24e10));
  assert(equal(material[1].lambda,  3.24e10));

  assert(equal(material[2].rho,      2730.0));
  assert(equal(material[2].mu,     3.396e10));
  assert(equal(material[2].lambda, 3.036e10));

  assert(equal(material[3].rho,      2850.0));
  assert(equal(material[3].mu,      4.02e10));
  assert(equal(material[3].lambda,  2.22e10));

  assert(equal(material[4].rho,      3000.0));
  assert(equal(material[4].mu,      4.80e10));
  assert(equal(material[4].lambda,  1.20e10));

  return 0;
}
