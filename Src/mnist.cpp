// This file is generated. Do not edit.
// Generated on: 02.07.2020 10:50:58

#include <cassert>

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/kernels/micro_ops.h"

namespace {

constexpr int kTensorArenaSize = 4100;
uint8_t tensor_arena[kTensorArenaSize] __attribute__((aligned(16)));
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
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[16];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[9];

const TfArray<4, int> tensor_dimension0 = { 4, { 1,28,28,1 } };
const TfArray<1, float> quant0_scale = { 1, { 0.0039215688593685627, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const int32_t tensor_data1[4] = { 1, 16, 12, 1, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const int32_t tensor_data2[10] = { -385, 1271, 8, -594, 73, 490, -68, -68, -624, -237, };
const TfArray<1, int> tensor_dimension2 = { 1, { 10 } };
const TfArray<1, float> quant2_scale = { 1, { 0.00069142924621701241, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const int32_t tensor_data3[2] = { -1, 20, };
const TfArray<1, int> tensor_dimension3 = { 1, { 2 } };
const int8_t tensor_data4[10*20] = { 
  -5, 16, -18, -29, 32, 8, -66, 5, -32, 77, 26, -29, -54, -48, -80, 55, 55, 30, 43, -46, 
  -26, -27, -40, 28, -25, 7, -1, 2, -58, -84, -65, 70, -112, -116, -36, 49, -51, -38, 19, 40, 
  15, -5, 82, -25, -22, -5, 63, -26, -47, -11, 22, 18, 79, -25, -45, -4, 24, -26, 36, -39, 
  28, 25, 58, -47, -5, -26, 61, -55, 42, -38, -9, 22, -15, 10, 53, -35, 74, 49, -25, -37, 
  -48, -9, -127, 37, -8, 23, -83, 46, -44, -6, -65, 33, 45, 23, 57, -8, -109, -79, -28, 16, 
  -1, 2, -2, -26, 11, 11, -40, -21, 10, 8, 30, -90, -25, 103, 59, -15, 69, 64, -15, -10, 
  30, -86, -3, 66, 8, -24, -65, 32, 24, -37, -101, -30, 24, 59, -20, 16, 19, 9, 41, -39, 
  -55, 29, 2, -10, 26, -10, 68, -2, 18, 34, 45, 15, -42, -85, -32, 14, -71, -82, -61, 39, 
  22, 14, 3, -11, -4, 27, 14, 3, 24, 21, -10, -20, 6, 11, 9, -44, 10, 14, -6, 43, 
  1, 36, 54, -83, 19, -65, -12, 39, 26, 41, 1, -10, 25, -17, 22, 28, -81, -37, -67, 10, 
};
const TfArray<2, int> tensor_dimension4 = { 2, { 10,20 } };
const TfArray<1, float> quant4_scale = { 1, { 0.016382781788706779, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const int8_t tensor_data5[12*3*3*1] = { 
  /* [0][0][][] */ -101, -127, -74, 
  /* [0][1][][] */ 36, 33, 103, 
  /* [0][2][][] */ 108, 40, 63, 
  /* [1][0][][] */ -25, -37, 58, 
  /* [1][1][][] */ 127, 100, 82, 
  /* [1][2][][] */ 25, -92, -111, 
  /* [2][0][][] */ -46, -105, -102, 
  /* [2][1][][] */ 36, -103, -103, 
  /* [2][2][][] */ -127, -2, 85, 
  /* [3][0][][] */ -20, 17, 66, 
  /* [3][1][][] */ -49, -127, -2, 
  /* [3][2][][] */ 45, -33, 4, 
  /* [4][0][][] */ -63, -74, -90, 
  /* [4][1][][] */ 66, 2, -127, 
  /* [4][2][][] */ 81, 81, -7, 
  /* [5][0][][] */ -116, -80, 3, 
  /* [5][1][][] */ 42, -10, -127, 
  /* [5][2][][] */ 38, -118, 3, 
  /* [6][0][][] */ -39, -28, -54, 
  /* [6][1][][] */ -127, -58, -58, 
  /* [6][2][][] */ 54, 18, 64, 
  /* [7][0][][] */ -29, -24, -29, 
  /* [7][1][][] */ -27, -127, -81, 
  /* [7][2][][] */ 15, -3, -82, 
  /* [8][0][][] */ 37, 83, 120, 
  /* [8][1][][] */ -88, 11, 44, 
  /* [8][2][][] */ -127, -96, -97, 
  /* [9][0][][] */ 75, 62, -119, 
  /* [9][1][][] */ 83, 39, -94, 
  /* [9][2][][] */ 127, -25, -113, 
  /* [10][0][][] */ -12, -127, 38, 
  /* [10][1][][] */ 50, 59, 29, 
  /* [10][2][][] */ -115, -9, -22, 
  /* [11][0][][] */ -19, -18, 66, 
  /* [11][1][][] */ -127, 19, -122, 
  /* [11][2][][] */ -52, -116, 54, 
};
const TfArray<4, int> tensor_dimension5 = { 4, { 12,3,3,1 } };
const TfArray<12, float> quant5_scale = { 12, { 0.011137373745441437, 0.0063731684349477291, 0.0015103225596249104, 0.0073724072426557541, 0.013132642954587936, 0.0014693656703457236, 0.0066396198235452175, 0.0020124090369790792, 0.013483083806931973, 0.01254712138324976, 0.0019273144425824285, 0.0017809931887313724, } };
const TfArray<12, int> quant5_zero = { 12, { 0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const int32_t tensor_data6[12] = { -16631, -23068, -100259, -13938, -5182, -48817, -14861, -24590, -2220, 5756, -10946, -10831, };
const TfArray<1, int> tensor_dimension6 = { 1, { 12 } };
const TfArray<12, float> quant6_scale = { 12, { 4.3675976485246792e-05, 2.499281799828168e-05, 5.9228341342532076e-06, 2.8911403205711395e-05, 5.1500563131412491e-05, 5.7622187341621611e-06, 2.6037725547212176e-05, 7.8918010331108235e-06, 5.287484236760065e-05, 4.9204401875613257e-05, 7.5580965130939148e-06, 6.9842872107983567e-06, } };
const TfArray<12, int> quant6_zero = { 12, { 0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const TfArray<4, int> tensor_dimension7 = { 4, { 1,13,13,12 } };
const TfArray<1, float> quant7_scale = { 1, { 0.042204629629850388, } };
const TfArray<1, int> quant7_zero = { 1, { 5 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const TfArray<4, int> tensor_dimension8 = { 4, { 1,4,4,12 } };
const TfArray<1, float> quant8_scale = { 1, { 0.042204629629850388, } };
const TfArray<1, int> quant8_zero = { 1, { 5 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<4, int> tensor_dimension9 = { 4, { 1,16,12,1 } };
const TfArray<1, float> quant9_scale = { 1, { 0.042204629629850388, } };
const TfArray<1, int> quant9_zero = { 1, { 5 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<4, int> tensor_dimension10 = { 4, { 1,5,4,1 } };
const TfArray<1, float> quant10_scale = { 1, { 0.042204629629850388, } };
const TfArray<1, int> quant10_zero = { 1, { 5 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfArray<2, int> tensor_dimension11 = { 2, { 1,20 } };
const TfArray<1, float> quant11_scale = { 1, { 0.042204629629850388, } };
const TfArray<1, int> quant11_zero = { 1, { 5 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<2, int> tensor_dimension12 = { 2, { 1,10 } };
const TfArray<1, float> quant12_scale = { 1, { 0.1216689869761467, } };
const TfArray<1, int> quant12_zero = { 1, { 18 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<2, int> tensor_dimension13 = { 2, { 1,10 } };
const TfArray<1, float> quant13_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,28,28,1 } };
const TfArray<2, int> tensor_dimension15 = { 2, { 1,10 } };
const TfArray<1, int> inputs0 = { 1, { 14 } };
const TfArray<1, int> outputs0 = { 1, { 0 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingValid, 2,2, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 0,5,6 } };
const TfArray<1, int> outputs1 = { 1, { 7 } };
const TfLitePoolParams opdata2 = { kTfLitePaddingValid, 3,3, 3,3, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs2 = { 1, { 7 } };
const TfArray<1, int> outputs2 = { 1, { 8 } };
const TfLiteReshapeParams opdata3 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs3 = { 2, { 8,1 } };
const TfArray<1, int> outputs3 = { 1, { 9 } };
const TfLitePoolParams opdata4 = { kTfLitePaddingValid, 3,3, 3,3, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs4 = { 1, { 9 } };
const TfArray<1, int> outputs4 = { 1, { 10 } };
const TfLiteReshapeParams opdata5 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs5 = { 2, { 10,3 } };
const TfArray<1, int> outputs5 = { 1, { 11 } };
const TfLiteFullyConnectedParams opdata6 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs6 = { 3, { 11,4,2 } };
const TfArray<1, int> outputs6 = { 1, { 12 } };
const TfLiteSoftmaxParams opdata7 = { 1 };
const TfArray<1, int> inputs7 = { 1, { 12 } };
const TfArray<1, int> outputs7 = { 1, { 13 } };
const TfArray<1, int> inputs8 = { 1, { 13 } };
const TfArray<1, int> outputs8 = { 1, { 15 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteInt8, tensor_arena + 3136, (TfLiteIntArray*)&tensor_dimension0, 784, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 40, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteInt8, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 108, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 48, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension7, 2028, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteInt8, tensor_arena + 2032, (TfLiteIntArray*)&tensor_dimension8, 192, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension9, 192, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteInt8, tensor_arena + 192, (TfLiteIntArray*)&tensor_dimension10, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension11, 20, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteInt8, tensor_arena + 32, (TfLiteIntArray*)&tensor_dimension12, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteInt8, tensor_arena + 48, (TfLiteIntArray*)&tensor_dimension13, 10, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteFloat32, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 3136, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension15, 40, {kTfLiteNoQuantization, nullptr}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, nullptr, OP_QUANTIZE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_SOFTMAX, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, nullptr, OP_DEQUANTIZE, },
};
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  static uint8_t *AllocPtr = tensor_arena + sizeof(tensor_arena);

  AllocPtr -= bytes;
  *ptr = AllocPtr;
  return kTfLiteOk;
}
} // namespace

TfLiteStatus mnist_init() {
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 16;
  for(size_t i = 0; i < 16; ++i) {
    tflTensors[i].data.data = tensorData[i].data;
    tflTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
  }
  registrations[OP_QUANTIZE] = tflite::ops::micro::Register_QUANTIZE();
  registrations[OP_CONV_2D] = tflite::ops::micro::Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = tflite::ops::micro::Register_MAX_POOL_2D();
  registrations[OP_RESHAPE] = tflite::ops::micro::Register_RESHAPE();
  registrations[OP_FULLY_CONNECTED] = tflite::ops::micro::Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = tflite::ops::micro::Register_SOFTMAX();
  registrations[OP_DEQUANTIZE] = tflite::ops::micro::Register_DEQUANTIZE();

  for(size_t i = 0; i < 9; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 9; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
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
TfLiteTensor* mnist_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  15, 
};
TfLiteTensor* mnist_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus mnist_invoke() {
  for(size_t i = 0; i < 9; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}
