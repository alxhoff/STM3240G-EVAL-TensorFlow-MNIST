// This file is generated. Do not edit.
// Generated on: 17.06.2020 15:33:37

#include <cassert>

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/kernels/micro_ops.h"

namespace {

constexpr int kTensorArenaSize = 4100;
uint8_t g_tensor_arena[kTensorArenaSize] __attribute__((aligned(16)));
template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_QUANTIZE, OP_CONV_2D, OP_MAX_POOL_2D, OP_RESHAPE, OP_FULLY_CONNECTED, OP_SOFTMAX, OP_DEQUANTIZE,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  // TfLiteQuantizationParams params;
  // TfLiteAllocationType allocation_type;
  size_t bytes;
  const char* name;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext g_ctx{};
TfLiteTensor g_tensors[16];
TfLiteRegistration *g_registrations[OP_LAST];
TfLiteNode g_nodes[9];

const TfArray<4, int> mnist_tensor_dimension0 = { 4, { 1,28,28,1 } };
const TfArray<1, float> mnist_quant0_scale = { 1, { 0.0039215688593685627, } };
const TfArray<1, int> mnist_quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization mnist_quant0 = { (TfLiteFloatArray*)&mnist_quant0_scale, (TfLiteIntArray*)&mnist_quant0_zero, 0 };
const int32_t mnist_tensor_data1[4] = { 1, 16, 12, 1, };
const TfArray<1, int> mnist_tensor_dimension1 = { 1, { 4 } };
const int32_t mnist_tensor_data2[10] = { -437, 734, -16, -561, 153, 577, 45, 177, -410, 4, };
const TfArray<1, int> mnist_tensor_dimension2 = { 1, { 10 } };
const TfArray<1, float> mnist_quant2_scale = { 1, { 0.00081934739137068391, } };
const TfArray<1, int> mnist_quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization mnist_quant2 = { (TfLiteFloatArray*)&mnist_quant2_scale, (TfLiteIntArray*)&mnist_quant2_zero, 0 };
const int32_t mnist_tensor_data3[2] = { -1, 20, };
const TfArray<1, int> mnist_tensor_dimension3 = { 1, { 2 } };
const int8_t mnist_tensor_data4[10*20] = { 
  11, -17, 0, 4, 50, 14, -32, 12, -30, -41, 38, 47, 0, -58, -49, -53, -34, 54, 39, 35, 
  9, -76, 24, -21, -9, -6, -5, -26, 52, -127, 14, -80, 33, -115, 6, -97, 32, -45, 22, -55, 
  4, 15, 36, 39, -38, 26, 21, -9, -33, -29, 22, -1, 32, 77, -68, 21, -7, 21, -7, 1, 
  -9, 54, 11, 60, -40, 38, 10, -21, 11, 29, 2, 3, -33, -10, 27, 20, -21, 80, -46, 19, 
  -13, -39, 40, -19, 48, -52, -4, -6, 12, -60, -39, -84, 35, 37, 38, 58, -8, -95, -11, -99, 
  -12, 19, -17, 25, 13, 11, -11, 10, -50, 61, -65, 19, -49, -13, 45, 61, 11, 78, -7, 35, 
  67, -40, -6, -36, 27, -47, -30, -33, -21, 39, -104, -40, 18, 18, -8, 36, -4, 7, 39, 39, 
  -40, 47, -11, -11, -1, 6, 33, 41, -13, 22, 52, 44, 22, -22, -52, -66, 23, -88, -22, -88, 
  -2, 36, -10, 32, -20, -9, 24, 22, -21, 23, -12, 7, 15, -34, 19, 31, -17, -17, 0, 23, 
  -37, 77, -44, 18, 44, -6, -37, -30, -22, 7, 29, 45, 9, 3, 28, 19, 0, -106, -38, -75, 
};
const TfArray<2, int> mnist_tensor_dimension4 = { 2, { 10,20 } };
const TfArray<1, float> mnist_quant4_scale = { 1, { 0.015650354325771332, } };
const TfArray<1, int> mnist_quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization mnist_quant4 = { (TfLiteFloatArray*)&mnist_quant4_scale, (TfLiteIntArray*)&mnist_quant4_zero, 0 };
const int8_t mnist_tensor_data5[12*3*3*1] = { 
  /* [0][0][][] */ 105, -66, 58, 
  /* [0][1][][] */ 82, 69, -107, 
  /* [0][2][][] */ -127, 32, -66, 
  /* [1][0][][] */ -78, 73, 127, 
  /* [1][1][][] */ -41, 29, 41, 
  /* [1][2][][] */ 103, 80, 45, 
  /* [2][0][][] */ 99, 84, 118, 
  /* [2][1][][] */ 15, 81, -87, 
  /* [2][2][][] */ -17, -127, -88, 
  /* [3][0][][] */ -120, -50, -117, 
  /* [3][1][][] */ -71, -34, -11, 
  /* [3][2][][] */ 127, 89, 98, 
  /* [4][0][][] */ 102, 97, 109, 
  /* [4][1][][] */ 32, 16, -30, 
  /* [4][2][][] */ -127, -116, -114, 
  /* [5][0][][] */ -127, -39, -70, 
  /* [5][1][][] */ 50, 45, 86, 
  /* [5][2][][] */ -42, 0, -127, 
  /* [6][0][][] */ 117, 104, -16, 
  /* [6][1][][] */ -54, 50, 48, 
  /* [6][2][][] */ -127, -20, 103, 
  /* [7][0][][] */ 29, 2, 12, 
  /* [7][1][][] */ 59, 1, 81, 
  /* [7][2][][] */ 84, 127, 39, 
  /* [8][0][][] */ 92, -73, 24, 
  /* [8][1][][] */ -31, -54, 49, 
  /* [8][2][][] */ -19, -127, 80, 
  /* [9][0][][] */ 34, -120, -111, 
  /* [9][1][][] */ -46, 18, -73, 
  /* [9][2][][] */ -127, 18, -109, 
  /* [10][0][][] */ 61, -103, -115, 
  /* [10][1][][] */ 127, 66, 47, 
  /* [10][2][][] */ -30, 15, 103, 
  /* [11][0][][] */ -1, 2, -60, 
  /* [11][1][][] */ -8, -6, 61, 
  /* [11][2][][] */ -68, -113, -127, 
};
const TfArray<4, int> mnist_tensor_dimension5 = { 4, { 12,3,3,1 } };
const TfArray<12, float> mnist_quant5_scale = { 12, { 0.0017798305489122868, 0.015230754390358925, 0.0011290539987385273, 0.013065524399280548, 0.0077249160967767239, 0.0015447826590389013, 0.016516430303454399, 0.0036010118201375008, 0.0018934342078864574, 0.0018222760409116745, 0.011138875968754292, 0.002214064123108983, } };
const TfArray<12, int> mnist_quant5_zero = { 12, { 0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization mnist_quant5 = { (TfLiteFloatArray*)&mnist_quant5_scale, (TfLiteIntArray*)&mnist_quant5_zero, 0 };
const int32_t mnist_tensor_data6[12] = { -13826, -705, -23931, -10827, -10387, -16066, 1056, 7497, -8488, -26368, -18051, 63440, };
const TfArray<1, int> mnist_tensor_dimension6 = { 1, { 12 } };
const TfArray<12, float> mnist_quant6_scale = { 12, { 6.979727913858369e-06, 5.972845247015357e-05, 4.427663043315988e-06, 5.1237355364719406e-05, 3.0293789677671157e-05, 6.0579714045161381e-06, 6.4770320022944361e-05, 1.4121616004558746e-05, 7.4252325248380657e-06, 7.146180905692745e-06, 4.3681870010914281e-05, 8.682604857312981e-06, } };
const TfArray<12, int> mnist_quant6_zero = { 12, { 0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization mnist_quant6 = { (TfLiteFloatArray*)&mnist_quant6_scale, (TfLiteIntArray*)&mnist_quant6_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension7 = { 4, { 1,13,13,12 } };
const TfArray<1, float> mnist_quant7_scale = { 1, { 0.052353281527757645, } };
const TfArray<1, int> mnist_quant7_zero = { 1, { -17 } };
const TfLiteAffineQuantization mnist_quant7 = { (TfLiteFloatArray*)&mnist_quant7_scale, (TfLiteIntArray*)&mnist_quant7_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension8 = { 4, { 1,4,4,12 } };
const TfArray<1, float> mnist_quant8_scale = { 1, { 0.052353281527757645, } };
const TfArray<1, int> mnist_quant8_zero = { 1, { -17 } };
const TfLiteAffineQuantization mnist_quant8 = { (TfLiteFloatArray*)&mnist_quant8_scale, (TfLiteIntArray*)&mnist_quant8_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension9 = { 4, { 1,16,12,1 } };
const TfArray<1, float> mnist_quant9_scale = { 1, { 0.052353281527757645, } };
const TfArray<1, int> mnist_quant9_zero = { 1, { -17 } };
const TfLiteAffineQuantization mnist_quant9 = { (TfLiteFloatArray*)&mnist_quant9_scale, (TfLiteIntArray*)&mnist_quant9_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension10 = { 4, { 1,5,4,1 } };
const TfArray<1, float> mnist_quant10_scale = { 1, { 0.052353281527757645, } };
const TfArray<1, int> mnist_quant10_zero = { 1, { -17 } };
const TfLiteAffineQuantization mnist_quant10 = { (TfLiteFloatArray*)&mnist_quant10_scale, (TfLiteIntArray*)&mnist_quant10_zero, 0 };
const TfArray<2, int> mnist_tensor_dimension11 = { 2, { 1,20 } };
const TfArray<1, float> mnist_quant11_scale = { 1, { 0.052353281527757645, } };
const TfArray<1, int> mnist_quant11_zero = { 1, { -17 } };
const TfLiteAffineQuantization mnist_quant11 = { (TfLiteFloatArray*)&mnist_quant11_scale, (TfLiteIntArray*)&mnist_quant11_zero, 0 };
const TfArray<2, int> mnist_tensor_dimension12 = { 2, { 1,10 } };
const TfArray<1, float> mnist_quant12_scale = { 1, { 0.11247973144054413, } };
const TfArray<1, int> mnist_quant12_zero = { 1, { 15 } };
const TfLiteAffineQuantization mnist_quant12 = { (TfLiteFloatArray*)&mnist_quant12_scale, (TfLiteIntArray*)&mnist_quant12_zero, 0 };
const TfArray<2, int> mnist_tensor_dimension13 = { 2, { 1,10 } };
const TfArray<1, float> mnist_quant13_scale = { 1, { 0.00390625, } };
const TfArray<1, int> mnist_quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization mnist_quant13 = { (TfLiteFloatArray*)&mnist_quant13_scale, (TfLiteIntArray*)&mnist_quant13_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension14 = { 4, { 1,28,28,1 } };
const TfArray<2, int> mnist_tensor_dimension15 = { 2, { 1,10 } };
const TfArray<1, int> mnist_inputs0 = { 1, { 14 } };
const TfArray<1, int> mnist_outputs0 = { 1, { 0 } };
const TfLiteConvParams mnist_opdata1 = { kTfLitePaddingValid, 2,2, kTfLiteActNone, 1,1 };
const TfArray<3, int> mnist_inputs1 = { 3, { 0,5,6 } };
const TfArray<1, int> mnist_outputs1 = { 1, { 7 } };
const TfLitePoolParams mnist_opdata2 = { kTfLitePaddingValid, 3,3, 3,3, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> mnist_inputs2 = { 1, { 7 } };
const TfArray<1, int> mnist_outputs2 = { 1, { 8 } };
const TfLiteReshapeParams mnist_opdata3 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> mnist_inputs3 = { 2, { 8,1 } };
const TfArray<1, int> mnist_outputs3 = { 1, { 9 } };
const TfLitePoolParams mnist_opdata4 = { kTfLitePaddingValid, 3,3, 3,3, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> mnist_inputs4 = { 1, { 9 } };
const TfArray<1, int> mnist_outputs4 = { 1, { 10 } };
const TfLiteReshapeParams mnist_opdata5 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> mnist_inputs5 = { 2, { 10,3 } };
const TfArray<1, int> mnist_outputs5 = { 1, { 11 } };
const TfLiteFullyConnectedParams mnist_opdata6 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> mnist_inputs6 = { 3, { 11,4,2 } };
const TfArray<1, int> mnist_outputs6 = { 1, { 12 } };
const TfLiteSoftmaxParams mnist_opdata7 = { 1 };
const TfArray<1, int> mnist_inputs7 = { 1, { 12 } };
const TfArray<1, int> mnist_outputs7 = { 1, { 13 } };
const TfArray<1, int> mnist_inputs8 = { 1, { 13 } };
const TfArray<1, int> mnist_outputs8 = { 1, { 15 } };
const TensorInfo_t tensors[] = {
  { kTfLiteInt8, g_tensor_arena + 3136, (TfLiteIntArray*)&mnist_tensor_dimension0, 784, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant0))}, },
  { kTfLiteInt32, (void*)mnist_tensor_data1, (TfLiteIntArray*)&mnist_tensor_dimension1, 16, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteInt32, (void*)mnist_tensor_data2, (TfLiteIntArray*)&mnist_tensor_dimension2, 40, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant2))}, },
  { kTfLiteInt32, (void*)mnist_tensor_data3, (TfLiteIntArray*)&mnist_tensor_dimension3, 8, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteInt8, (void*)mnist_tensor_data4, (TfLiteIntArray*)&mnist_tensor_dimension4, 200, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant4))}, },
  { kTfLiteInt8, (void*)mnist_tensor_data5, (TfLiteIntArray*)&mnist_tensor_dimension5, 108, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant5))}, },
  { kTfLiteInt32, (void*)mnist_tensor_data6, (TfLiteIntArray*)&mnist_tensor_dimension6, 48, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant6))}, },
  { kTfLiteInt8, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension7, 2028, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant7))}, },
  { kTfLiteInt8, g_tensor_arena + 2032, (TfLiteIntArray*)&mnist_tensor_dimension8, 192, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant8))}, },
  { kTfLiteInt8, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension9, 192, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant9))}, },
  { kTfLiteInt8, g_tensor_arena + 192, (TfLiteIntArray*)&mnist_tensor_dimension10, 20, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant10))}, },
  { kTfLiteInt8, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension11, 20, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant11))}, },
  { kTfLiteInt8, g_tensor_arena + 32, (TfLiteIntArray*)&mnist_tensor_dimension12, 10, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant12))}, },
  { kTfLiteInt8, g_tensor_arena + 48, (TfLiteIntArray*)&mnist_tensor_dimension13, 10, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant13))}, },
  { kTfLiteFloat32, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension14, 3136, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension15, 40, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
};const NodeInfo_t nodes[] = {
  { (TfLiteIntArray*)&mnist_inputs0, (TfLiteIntArray*)&mnist_outputs0, nullptr, OP_QUANTIZE, },
  { (TfLiteIntArray*)&mnist_inputs1, (TfLiteIntArray*)&mnist_outputs1, const_cast<void*>(static_cast<const void*>(&mnist_opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&mnist_inputs2, (TfLiteIntArray*)&mnist_outputs2, const_cast<void*>(static_cast<const void*>(&mnist_opdata2)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&mnist_inputs3, (TfLiteIntArray*)&mnist_outputs3, const_cast<void*>(static_cast<const void*>(&mnist_opdata3)), OP_RESHAPE, },
  { (TfLiteIntArray*)&mnist_inputs4, (TfLiteIntArray*)&mnist_outputs4, const_cast<void*>(static_cast<const void*>(&mnist_opdata4)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&mnist_inputs5, (TfLiteIntArray*)&mnist_outputs5, const_cast<void*>(static_cast<const void*>(&mnist_opdata5)), OP_RESHAPE, },
  { (TfLiteIntArray*)&mnist_inputs6, (TfLiteIntArray*)&mnist_outputs6, const_cast<void*>(static_cast<const void*>(&mnist_opdata6)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&mnist_inputs7, (TfLiteIntArray*)&mnist_outputs7, const_cast<void*>(static_cast<const void*>(&mnist_opdata7)), OP_SOFTMAX, },
  { (TfLiteIntArray*)&mnist_inputs8, (TfLiteIntArray*)&mnist_outputs8, nullptr, OP_DEQUANTIZE, },
};
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  static uint8_t *AllocPtr = g_tensor_arena + sizeof(g_tensor_arena);

  AllocPtr -= bytes;
  *ptr = AllocPtr;
  return kTfLiteOk;
}
} // namespace

TfLiteStatus mnist_init() {
  g_ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  g_ctx.tensors = g_tensors;
  g_ctx.tensors_size = 16;
  for(size_t i = 0; i < 16; ++i) {
    g_tensors[i].data.data = tensors[i].data;
    g_tensors[i].type = tensors[i].type;
    g_tensors[i].is_variable = false;
    g_tensors[i].allocation_type = (g_tensor_arena <= tensors[i].data && tensors[i].data < g_tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
    g_tensors[i].bytes = tensors[i].bytes;
    g_tensors[i].dims = tensors[i].dims;
    g_tensors[i].quantization = tensors[i].quantization;
    if (tensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensors[i].quantization.params));
      g_tensors[i].params.scale = quant->scale->data[0];
      g_tensors[i].params.zero_point = quant->zero_point->data[0];
    }
  }
  g_registrations[OP_QUANTIZE] = tflite::ops::micro::Register_QUANTIZE();
  g_registrations[OP_CONV_2D] = tflite::ops::micro::Register_CONV_2D();
  g_registrations[OP_MAX_POOL_2D] = tflite::ops::micro::Register_MAX_POOL_2D();
  g_registrations[OP_RESHAPE] = tflite::ops::micro::Register_RESHAPE();
  g_registrations[OP_FULLY_CONNECTED] = tflite::ops::micro::Register_FULLY_CONNECTED();
  g_registrations[OP_SOFTMAX] = tflite::ops::micro::Register_SOFTMAX();
  g_registrations[OP_DEQUANTIZE] = tflite::ops::micro::Register_DEQUANTIZE();

  for(size_t i = 0; i < 9; ++i) {
    g_nodes[i].inputs = nodes[i].inputs;
    g_nodes[i].outputs = nodes[i].outputs;
    g_nodes[i].temporaries = nullptr;
    g_nodes[i].builtin_data = nodes[i].builtin_data;
    g_nodes[i].custom_initial_data = nullptr;
    g_nodes[i].custom_initial_data_size = 0;
    g_nodes[i].delegate = nullptr;
    if (g_registrations[nodes[i].used_op_index]->init) {
      g_nodes[i].user_data = g_registrations[nodes[i].used_op_index]->init(&g_ctx, (const char*)g_nodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 9; ++i) {
    if (g_registrations[nodes[i].used_op_index]->prepare) {
      TfLiteStatus status = g_registrations[nodes[i].used_op_index]->prepare(&g_ctx, &g_nodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  14, 
};
void *mnist_input_ptr(int index) {
  return g_ctx.tensors[inTensorIndices[index]].data.data;
}
size_t mnist_input_size(int index) {
  return g_ctx.tensors[inTensorIndices[index]].bytes;
}
TfLiteTensor* mnist_input(int index) {
  return &g_ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  15, 
};
const void *mnist_output_ptr(int index) {
  return g_ctx.tensors[outTensorIndices[index]].data.data;
}
size_t mnist_output_size(int index) {
  return g_ctx.tensors[outTensorIndices[index]].bytes;
}
TfLiteTensor* mnist_output(int index) {
  return &g_ctx.tensors[outTensorIndices[index]];
}
int mnist_output_dims_len(int index) {
  return g_ctx.tensors[outTensorIndices[index]].dims->data[0];
}
const int *mnist_output_dims(int index) {
  return &g_ctx.tensors[outTensorIndices[index]].dims->data[1];
}

TfLiteStatus mnist_invoke() {
  for(size_t i = 0; i < 9; ++i) {
    TfLiteStatus status = g_registrations[nodes[i].used_op_index]->invoke(&g_ctx, &g_nodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}
