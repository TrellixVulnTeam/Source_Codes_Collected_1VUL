# Copyright (C) 2016-2018 Alibaba Group Holding Limited
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

import xdl
import unittest
import numpy as np
from xdl.python.lib.datatype import *
from xdl.python.lib.graph import execute

class TestPsSparsePullOp(unittest.TestCase):
    def test_all(self):
        var = xdl.Variable(name="w", dtype=DataType.int32, shape=[4,2], 
                           initializer=xdl.Ones())
        execute(xdl.variable_registers())
        execute(xdl.global_initializers())
        op = xdl.ps_sparse_pull_op(var_name="w", 
                                   var_type="index", 
                                   save_ratio=1.0,
                                   otype=DataType.int32,
                                   ids=np.array([1,3], dtype=np.int32))
        ret = execute(op)
        self.assertTrue((ret == np.array([[1,1],[1,1]])).all())

def suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestPsSparsePullOp)

if __name__ == '__main__':
    unittest.TextTestRunner().run(suite())
