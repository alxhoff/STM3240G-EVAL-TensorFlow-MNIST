/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/


using namespace std;

#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"

#include "main_functions.h"
#include "constants.h"

extern void mnist_init();
extern void mnist_invoke();
extern const size_t mnist_output_size(int idx=0);
extern const int *mnist_output_dims(int idx=0);
extern const int mnist_output_dims_len(int idx=0);

extern TfLiteTensor *mnist_input(int idx=0);
extern TfLiteTensor *mnist_output(int idx=0);

// The name of this function is important for Arduino compatibility.
void setup()
{
    mnist_init();
}

// The name of this function is important for Arduino compatibility.
float *loop(uint8_t *img, uint32_t size)
{
	for (uint32_t i = 0; i < size; i++)
        tflite::GetTensorData<float>(mnist_input())[0] = img[i];

    mnist_invoke();

    auto output_array = &tflite::GetTensorData<float>(mnist_output())[0];
    return output_array;
	// return (char)output->data.f[0] + 48;
}
