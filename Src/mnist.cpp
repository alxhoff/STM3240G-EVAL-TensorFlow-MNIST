// This file is generated. Do not edit.
// Generated on: 18.06.2020 11:03:29

#include <cassert>

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/kernels/micro_ops.h"

namespace {

constexpr int kTensorArenaSize = 4420;
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
TfLiteTensor g_tensors[13];
TfLiteRegistration *g_registrations[OP_LAST];
TfLiteNode g_nodes[7];

const TfArray<4, int> mnist_tensor_dimension0 = { 4, { 1,28,28,1 } };
const TfArray<1, float> mnist_quant0_scale = { 1, { 0.0039215688593685627, } };
const TfArray<1, int> mnist_quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization mnist_quant0 = { (TfLiteFloatArray*)&mnist_quant0_scale, (TfLiteIntArray*)&mnist_quant0_zero, 0 };
const int32_t mnist_tensor_data1[10] = { -253, 637, -264, -335, 199, 310, -188, 449, -463, 64, };
const TfArray<1, int> mnist_tensor_dimension1 = { 1, { 10 } };
const TfArray<1, float> mnist_quant1_scale = { 1, { 0.00030369576415978372, } };
const TfArray<1, int> mnist_quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization mnist_quant1 = { (TfLiteFloatArray*)&mnist_quant1_scale, (TfLiteIntArray*)&mnist_quant1_zero, 0 };
const int32_t mnist_tensor_data2[2] = { -1, 160, };
const TfArray<1, int> mnist_tensor_dimension2 = { 1, { 2 } };
const int8_t mnist_tensor_data3[10*160] = { 
  -7, -7, -21, 31, -5, -39, 14, 9, 5, -23, -18, -26, -11, 4, 14, 7, -18, -29, -5, -31, -13, -35, -54, -36, 14, -29, 28, 10, 49, -15, -9, -53, -7, 19, 8, 3, -10, 13, -10, -30, 17, -35, 21, -3, -9, 1, 10, 9, -19, -4, 35, 8, 32, -1, 4, 27, 17, 3, -5, 8, 41, -29, 24, -85, -25, 3, 16, 21, -75, -6, 25, 46, 27, -8, 40, 8, 14, 29, -46, -5, -8, -72, -3, -68, 11, -20, 4, 26, 15, -41, 12, -27, 30, 19, 12, 15, 11, 36, -33, -22, 28, -8, 11, -57, 10, 1, 6, -5, -28, -23, 5, 3, 5, -24, 23, 15, 16, 16, -65, 6, -56, 6, 16, 16, -24, -7, -42, 6, 19, 14, -34, -23, -30, -16, -8, -52, -35, -24, -4, 1, -14, -61, -69, 16, 26, -25, 25, 31, 52, -2, -6, -34, 12, 28, 10, 8, 9, 17, 20, 12, 
  -32, -21, -17, -35, -22, 13, -22, 22, -28, -21, -22, -30, -26, 26, -1, -27, -4, -16, -8, -20, -7, -25, 31, 7, -15, 26, -22, -21, -66, 23, -8, 27, -20, -6, -36, -16, -18, 4, -18, -5, 1, -43, -73, -79, 39, -59, 58, 18, -14, -70, 29, -93, 56, 23, 28, 23, 9, 24, -17, 38, -38, -35, -66, -17, 32, -42, 5, 51, 47, -7, 0, -76, -19, 16, 19, -24, -20, -17, 5, 5, 1, -14, -13, -5, 12, 15, -17, -7, -16, 25, -3, 5, -26, 12, 9, -23, -14, 2, -3, 20, -75, -38, -36, 16, -3, -1, -4, -3, -14, -15, -36, -24, -23, 20, -8, -15, -12, -27, -8, 6, 8, -45, -49, -1, 3, -1, 14, 16, -41, -30, 12, -13, 20, 15, 15, 1, 23, 21, -33, 38, -6, 26, 34, 1, 14, 26, -11, 1, -12, 23, -20, -4, -29, 29, 0, -30, 16, -1, 30, -25, 
  -27, -14, 44, 10, -12, 16, -19, -13, 2, 42, -32, 34, -27, -17, -22, 7, -15, -14, -3, 30, -46, -19, 69, 34, -28, 53, -2, -11, -22, 44, -24, 72, 0, -5, -27, -11, 10, -11, -7, -2, -1, -2, 36, -18, -21, 15, 0, 36, -27, 21, 22, 38, 0, -23, 12, 2, 30, -18, -13, -1, 20, -39, 3, -54, -8, -63, -2, 25, 18, -43, 25, -38, 27, -43, 49, -6, 9, 25, -59, 13, -6, -11, 11, 31, 3, -6, 9, 12, 12, 12, 6, 17, 28, -9, -7, -22, -17, -6, 24, 32, -23, -33, -17, 32, 27, -10, 8, -26, 83, -8, 4, -10, 14, 27, -6, 5, -19, -6, 29, 8, 18, 15, 9, -3, 2, -5, 12, -15, 32, 3, 3, 16, 5, -15, -4, 9, -42, -4, -6, 1, -19, 39, 37, -24, -15, 48, 14, -58, -20, 35, 4, 61, -8, 37, -40, 1, -4, 5, 50, -11, 
  -17, 4, 47, 54, -25, 32, -14, -36, -20, 50, -18, 60, -9, -30, -3, -18, 15, -1, -21, 41, -24, 48, 46, 41, -18, 56, 9, -33, -19, 59, -23, 76, -30, -4, -33, -15, -4, -25, 27, 6, 5, 16, 8, -10, 44, 19, -1, -64, 21, -1, 7, 25, 7, 6, -27, 26, -5, 20, 33, 19, -18, -28, -34, 62, 8, -40, -5, -59, -56, -1, -14, -59, 3, -11, -16, 3, -20, 9, -10, 1, 39, 84, 2, -21, -41, -6, 12, -5, -12, -16, 33, 11, 8, -8, 1, -12, 3, 4, 45, 4, -25, 52, -7, -23, -37, 28, -1, -7, 12, -9, -4, 2, -29, 4, -31, 8, 2, -4, 42, -16, -3, 15, 26, 35, -1, 34, 8, -34, -9, 20, -9, 51, 1, 4, -42, 9, 0, 4, 39, 1, 32, -7, -57, 10, -5, -33, -12, -10, -14, -9, 25, -48, -2, -40, 1, -2, 11, 1, -60, 14, 
  31, 19, -20, -38, -15, -9, 14, 12, -13, -25, 12, -31, -3, 16, -5, 2, -12, 12, 4, -10, 35, 15, -65, -31, 37, -52, 28, 5, 12, -61, 4, -85, 5, -5, 37, -7, 13, 35, -5, 30, -32, -31, -45, -59, -5, -95, -38, 63, 76, -75, -31, -88, -35, -39, 45, -27, 2, -5, -63, -44, -25, -26, -72, 31, 11, -66, -3, 54, 87, -53, -31, -70, 25, -10, 29, -37, 0, 33, -9, 28, 12, 25, -6, 14, 11, 9, 3, 2, 3, 8, -4, 9, -5, 21, 4, -16, -12, -1, 10, 10, 30, -22, 1, 30, -7, -4, 4, -9, -10, 12, 28, -9, 5, 21, -1, -3, -14, 15, 3, -4, -6, 35, -2, -43, -7, -20, 8, 24, -12, -35, 8, -16, 18, -3, 47, 22, 31, 21, -11, 6, -4, 14, 33, -4, -23, 38, 3, -23, -51, 20, 16, 42, -17, 19, -47, -6, -5, 13, 27, 11, 
  -30, -36, -15, -31, 12, 10, -4, 20, -7, -27, -25, -17, -15, 20, 16, -13, 19, -10, -11, 3, 30, 11, -19, -47, -9, -26, 14, 12, -9, -45, 18, -31, 11, 4, 25, 26, 23, -9, -3, -36, -10, 13, 37, 24, -1, 39, -7, -89, -50, 45, 5, 27, 7, -3, -84, -9, -34, 16, 4, 14, -46, 29, 58, 48, -4, 56, -8, -105, -55, 77, -32, 77, -21, 42, -127, -18, -30, -31, 53, -2, -1, 44, 23, 11, -21, 32, -4, 8, -25, 22, -4, 7, -10, -13, -27, -12, 14, -11, 18, -17, -5, 71, 20, 16, -38, 23, 16, -19, -53, 18, -4, 39, -6, -12, -2, 15, 21, 3, 28, -8, 8, 34, 39, 7, 3, 26, -28, -19, -40, 21, -4, 38, -39, 7, -4, -12, 25, -7, -8, 15, 25, 42, -23, -25, 2, -28, -28, 15, -31, -30, 12, -21, -16, -8, 14, -5, 16, -24, -17, -14, 
  -14, -35, -15, -8, 21, -60, 4, 11, 16, -54, -24, -22, 8, 17, 19, 15, -4, -8, -13, -42, -26, -56, -86, -5, -1, -76, 3, 28, 19, -56, -20, -84, -1, -3, 35, -11, -8, 5, -45, -38, -46, -24, -93, 39, 7, -54, -32, 7, 55, -14, -52, -53, -17, 6, -6, -57, -77, -19, 6, 4, 0, 44, 5, 5, 21, 12, -7, -75, 15, 14, -8, 31, -34, 31, -43, -4, -39, -23, 50, -47, -24, -68, -13, -38, 12, -6, -10, 23, 20, -38, -18, -28, -5, -12, 27, 21, -15, -10, -39, -48, 33, -59, 3, -72, -4, 11, 28, 33, -36, -3, 2, 20, 3, -18, 31, 8, 32, 21, -67, -12, 33, 15, 28, 28, 7, 41, 3, -39, 30, 57, 15, 58, 15, 11, -36, 13, -4, 1, 7, -3, -3, 37, -3, 11, 22, 6, 16, 14, 30, -17, 29, -16, 21, 36, 25, 31, -10, -7, 24, -11, 
  40, 19, -22, -19, -17, -13, 17, -9, -11, -6, 12, -8, -12, 31, -25, -1, 15, -1, 20, 3, 2, 43, 10, 22, 0, 39, 14, -36, -51, 12, 30, 41, -2, 29, -23, 33, 15, 21, 17, 27, -3, 22, 34, -1, -5, 39, 27, 5, -51, 23, 3, 34, 20, 19, -4, 25, 4, -5, -6, 9, -32, 19, -66, -8, -7, -32, 4, 0, 18, -24, -11, -51, 18, 27, -3, 14, -6, 3, 20, 15, -8, -1, -16, 37, 14, -7, -1, 1, -6, -7, -8, -28, -15, 17, -18, -11, -16, 2, -7, 46, -64, -16, -53, 82, 14, -31, -24, 6, 1, 7, -58, -51, 2, 2, -5, -28, -15, -13, -10, 23, -39, -83, -73, -31, 17, -75, -8, 59, 67, -49, -41, -82, 16, 1, 50, -28, -25, 23, -11, 2, -12, -19, 14, 29, 16, 30, -6, -49, -20, 45, 11, 26, -14, 7, -48, 0, 7, -9, 19, 24, 
  -10, -23, -9, -34, 3, 0, 15, 8, 29, -41, -8, -7, -3, -19, -12, 14, 13, -3, 14, -12, 67, -6, 55, -35, -8, 19, 0, 15, -11, -39, 9, 8, 23, -12, 9, -3, 20, 4, -26, -23, 32, 18, 16, -3, 10, 8, -2, -7, 25, 13, 14, 8, -12, -4, 11, -21, 21, -17, 11, -10, 10, -1, -10, 43, 21, 1, -5, 16, 43, 20, 5, 9, 21, 2, 31, -10, -9, -7, -3, 9, -19, -30, 16, 15, 18, 4, -16, -8, 19, 18, -24, 31, -11, -12, -11, -12, 3, -28, -11, -6, 28, -23, -10, -54, 5, 9, -22, 13, 53, -43, 22, -14, -22, -23, 12, 11, 12, -10, -6, -17, 48, 6, 28, -5, -16, 10, 3, -25, -56, -5, 11, -25, 8, -21, -11, 8, 9, 16, 12, -20, 20, -2, 30, 28, -9, 16, -4, -12, -31, 31, -13, 28, -13, -38, -8, -2, 4, -15, -47, 7, 
  13, 8, -38, -30, 14, -57, 5, 2, 23, -65, 22, -60, -3, 30, 31, 4, -10, 5, 10, -5, -2, 1, -40, 42, 31, 6, 0, -1, 53, 15, -27, -74, 28, 31, 6, -9, -8, 6, 26, 45, 21, -5, 24, 25, 9, 28, -16, -48, -28, 33, 5, -16, -5, 19, -29, 0, -3, -23, 15, 3, -6, -10, 8, -56, -7, -11, 1, -24, -33, -35, 9, 0, 4, 8, -4, -8, -1, 2, -25, -4, 16, -36, -26, -24, -1, -18, -8, -8, -11, -20, 6, -18, -1, 7, -15, 12, -4, 1, -21, -17, 15, -5, 4, 15, -31, 22, -1, -27, -38, 35, -1, 32, 3, -10, 1, 0, 2, -1, 7, -20, -55, -12, -21, -21, 3, -25, 0, 14, 24, -11, -28, -62, 21, 24, 32, 28, -19, 24, 9, -7, -2, -95, 5, -37, -7, -31, 4, 6, -9, -37, -12, -57, 29, -46, -25, 25, -7, -6, -53, 5, 
};
const TfArray<2, int> mnist_tensor_dimension3 = { 2, { 10,160 } };
const TfArray<1, float> mnist_quant3_scale = { 1, { 0.010578899644315243, } };
const TfArray<1, int> mnist_quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization mnist_quant3 = { (TfLiteFloatArray*)&mnist_quant3_scale, (TfLiteIntArray*)&mnist_quant3_zero, 0 };
const int8_t mnist_tensor_data4[20*3*3*1] = { 
  /* [0][0][][] */ 127, -9, -125, 
  /* [0][1][][] */ 47, 46, -76, 
  /* [0][2][][] */ -29, 78, 111, 
  /* [1][0][][] */ -86, -88, -127, 
  /* [1][1][][] */ 48, 39, -18, 
  /* [1][2][][] */ 101, 41, 44, 
  /* [2][0][][] */ 5, 76, 92, 
  /* [2][1][][] */ -50, 28, 79, 
  /* [2][2][][] */ -127, -114, -39, 
  /* [3][0][][] */ 84, 72, 27, 
  /* [3][1][][] */ 43, -3, -100, 
  /* [3][2][][] */ -127, -72, -52, 
  /* [4][0][][] */ -125, 26, 127, 
  /* [4][1][][] */ -54, 51, 37, 
  /* [4][2][][] */ 115, 94, 4, 
  /* [5][0][][] */ 34, 29, 62, 
  /* [5][1][][] */ 43, 106, 127, 
  /* [5][2][][] */ -102, -122, -109, 
  /* [6][0][][] */ 120, 71, 61, 
  /* [6][1][][] */ 77, 21, 92, 
  /* [6][2][][] */ 103, 83, 127, 
  /* [7][0][][] */ -77, -60, 89, 
  /* [7][1][][] */ -55, -20, 63, 
  /* [7][2][][] */ -127, -26, 62, 
  /* [8][0][][] */ 3, -127, 8, 
  /* [8][1][][] */ -68, -8, 63, 
  /* [8][2][][] */ -49, 46, 32, 
  /* [9][0][][] */ 38, 96, 89, 
  /* [9][1][][] */ -71, -43, -127, 
  /* [9][2][][] */ -119, -42, -88, 
  /* [10][0][][] */ 106, 34, -127, 
  /* [10][1][][] */ 46, 46, 50, 
  /* [10][2][][] */ -29, 36, 106, 
  /* [11][0][][] */ 18, 61, 83, 
  /* [11][1][][] */ -114, -27, 35, 
  /* [11][2][][] */ -97, -60, -127, 
  /* [12][0][][] */ 127, 119, 35, 
  /* [12][1][][] */ 27, 11, -72, 
  /* [12][2][][] */ 104, 38, 77, 
  /* [13][0][][] */ -71, -50, -6, 
  /* [13][1][][] */ 8, 84, 61, 
  /* [13][2][][] */ 127, 53, 113, 
  /* [14][0][][] */ -43, 55, 91, 
  /* [14][1][][] */ -127, 41, 45, 
  /* [14][2][][] */ -95, 70, 71, 
  /* [15][0][][] */ 122, 37, 32, 
  /* [15][1][][] */ 41, 4, 64, 
  /* [15][2][][] */ -52, 10, 127, 
  /* [16][0][][] */ 10, 94, 54, 
  /* [16][1][][] */ -127, 20, 75, 
  /* [16][2][][] */ -99, -67, 70, 
  /* [17][0][][] */ 89, 94, -66, 
  /* [17][1][][] */ 48, 65, -49, 
  /* [17][2][][] */ 127, 85, -12, 
  /* [18][0][][] */ -127, -90, -124, 
  /* [18][1][][] */ -118, -1, 42, 
  /* [18][2][][] */ 88, 81, 82, 
  /* [19][0][][] */ 89, 53, 52, 
  /* [19][1][][] */ 103, 56, 21, 
  /* [19][2][][] */ 35, -28, -127, 
};
const TfArray<4, int> mnist_tensor_dimension4 = { 4, { 20,3,3,1 } };
const TfArray<20, float> mnist_quant4_scale = { 20, { 0.0084481919184327126, 0.0096172085031867027, 0.0084440531209111214, 0.010594264604151249, 0.0067645101808011532, 0.0071310182102024555, 0.0047905221581459045, 0.010053480044007301, 0.011811571195721626, 0.00753052718937397, 0.006969955749809742, 0.0084587838500738144, 0.0049323667772114277, 0.0047907200641930103, 0.0085394466295838356, 0.0073281833902001381, 0.0053612086921930313, 0.0042933397926390171, 0.0074472394771873951, 0.0056163687258958817, } };
const TfArray<20, int> mnist_quant4_zero = { 20, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization mnist_quant4 = { (TfLiteFloatArray*)&mnist_quant4_scale, (TfLiteIntArray*)&mnist_quant4_zero, 0 };
const int32_t mnist_tensor_data5[20] = { -8909, -3144, -8423, -3084, -765, -4511, -9929, 2456, -5676, -4238, -6542, -7935, -8784, 10485, -1455, -6587, -709, -3970, -3764, 929, };
const TfArray<1, int> mnist_tensor_dimension5 = { 1, { 20 } };
const TfArray<20, float> mnist_quant5_scale = { 20, { 3.3130167139461264e-05, 3.7714544305345044e-05, 3.3113934478024021e-05, 4.1546136344550177e-05, 2.6527492082095705e-05, 2.7964779292233288e-05, 1.8786362488754094e-05, 3.9425412978744134e-05, 4.6319888497237116e-05, 2.9531480322475545e-05, 2.7333160687703639e-05, 3.317170194350183e-05, 1.9342616724316031e-05, 1.8787139197229408e-05, 3.3488027838757262e-05, 2.8737975299009122e-05, 2.1024348825449124e-05, 1.6836627764860168e-05, 2.9204862585174851e-05, 2.2024976715329103e-05, } };
const TfArray<20, int> mnist_quant5_zero = { 20, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization mnist_quant5 = { (TfLiteFloatArray*)&mnist_quant5_scale, (TfLiteIntArray*)&mnist_quant5_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension6 = { 4, { 1,13,13,20 } };
const TfArray<1, float> mnist_quant6_scale = { 1, { 0.028707690536975861, } };
const TfArray<1, int> mnist_quant6_zero = { 1, { 7 } };
const TfLiteAffineQuantization mnist_quant6 = { (TfLiteFloatArray*)&mnist_quant6_scale, (TfLiteIntArray*)&mnist_quant6_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension7 = { 4, { 1,2,4,20 } };
const TfArray<1, float> mnist_quant7_scale = { 1, { 0.028707690536975861, } };
const TfArray<1, int> mnist_quant7_zero = { 1, { 7 } };
const TfLiteAffineQuantization mnist_quant7 = { (TfLiteFloatArray*)&mnist_quant7_scale, (TfLiteIntArray*)&mnist_quant7_zero, 0 };
const TfArray<2, int> mnist_tensor_dimension8 = { 2, { 1,160 } };
const TfArray<1, float> mnist_quant8_scale = { 1, { 0.028707690536975861, } };
const TfArray<1, int> mnist_quant8_zero = { 1, { 7 } };
const TfLiteAffineQuantization mnist_quant8 = { (TfLiteFloatArray*)&mnist_quant8_scale, (TfLiteIntArray*)&mnist_quant8_zero, 0 };
const TfArray<2, int> mnist_tensor_dimension9 = { 2, { 1,10 } };
const TfArray<1, float> mnist_quant9_scale = { 1, { 0.13405424356460571, } };
const TfArray<1, int> mnist_quant9_zero = { 1, { 12 } };
const TfLiteAffineQuantization mnist_quant9 = { (TfLiteFloatArray*)&mnist_quant9_scale, (TfLiteIntArray*)&mnist_quant9_zero, 0 };
const TfArray<2, int> mnist_tensor_dimension10 = { 2, { 1,10 } };
const TfArray<1, float> mnist_quant10_scale = { 1, { 0.00390625, } };
const TfArray<1, int> mnist_quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization mnist_quant10 = { (TfLiteFloatArray*)&mnist_quant10_scale, (TfLiteIntArray*)&mnist_quant10_zero, 0 };
const TfArray<4, int> mnist_tensor_dimension11 = { 4, { 1,28,28,1 } };
const TfArray<2, int> mnist_tensor_dimension12 = { 2, { 1,10 } };
const TfArray<1, int> mnist_inputs0 = { 1, { 11 } };
const TfArray<1, int> mnist_outputs0 = { 1, { 0 } };
const TfLiteConvParams mnist_opdata1 = { kTfLitePaddingValid, 2,2, kTfLiteActNone, 1,1 };
const TfArray<3, int> mnist_inputs1 = { 3, { 0,4,5 } };
const TfArray<1, int> mnist_outputs1 = { 1, { 6 } };
const TfLitePoolParams mnist_opdata2 = { kTfLitePaddingValid, 3,6, 3,6, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> mnist_inputs2 = { 1, { 6 } };
const TfArray<1, int> mnist_outputs2 = { 1, { 7 } };
const TfLiteReshapeParams mnist_opdata3 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> mnist_inputs3 = { 2, { 7,2 } };
const TfArray<1, int> mnist_outputs3 = { 1, { 8 } };
const TfLiteFullyConnectedParams mnist_opdata4 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> mnist_inputs4 = { 3, { 8,3,1 } };
const TfArray<1, int> mnist_outputs4 = { 1, { 9 } };
const TfLiteSoftmaxParams mnist_opdata5 = { 1 };
const TfArray<1, int> mnist_inputs5 = { 1, { 9 } };
const TfArray<1, int> mnist_outputs5 = { 1, { 10 } };
const TfArray<1, int> mnist_inputs6 = { 1, { 10 } };
const TfArray<1, int> mnist_outputs6 = { 1, { 12 } };
const TensorInfo_t tensors[] = {
  { kTfLiteInt8, g_tensor_arena + 3392, (TfLiteIntArray*)&mnist_tensor_dimension0, 784, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant0))}, },
  { kTfLiteInt32, (void*)mnist_tensor_data1, (TfLiteIntArray*)&mnist_tensor_dimension1, 40, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant1))}, },
  { kTfLiteInt32, (void*)mnist_tensor_data2, (TfLiteIntArray*)&mnist_tensor_dimension2, 8, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteInt8, (void*)mnist_tensor_data3, (TfLiteIntArray*)&mnist_tensor_dimension3, 1600, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant3))}, },
  { kTfLiteInt8, (void*)mnist_tensor_data4, (TfLiteIntArray*)&mnist_tensor_dimension4, 180, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant4))}, },
  { kTfLiteInt32, (void*)mnist_tensor_data5, (TfLiteIntArray*)&mnist_tensor_dimension5, 80, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant5))}, },
  { kTfLiteInt8, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension6, 3380, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant6))}, },
  { kTfLiteInt8, g_tensor_arena + 3392, (TfLiteIntArray*)&mnist_tensor_dimension7, 160, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant7))}, },
  { kTfLiteInt8, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension8, 160, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant8))}, },
  { kTfLiteInt8, g_tensor_arena + 160, (TfLiteIntArray*)&mnist_tensor_dimension9, 10, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant9))}, },
  { kTfLiteInt8, g_tensor_arena + 48, (TfLiteIntArray*)&mnist_tensor_dimension10, 10, "NO-NAME", {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&mnist_quant10))}, },
  { kTfLiteFloat32, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension11, 3136, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, g_tensor_arena + 0, (TfLiteIntArray*)&mnist_tensor_dimension12, 40, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
};const NodeInfo_t nodes[] = {
  { (TfLiteIntArray*)&mnist_inputs0, (TfLiteIntArray*)&mnist_outputs0, nullptr, OP_QUANTIZE, },
  { (TfLiteIntArray*)&mnist_inputs1, (TfLiteIntArray*)&mnist_outputs1, const_cast<void*>(static_cast<const void*>(&mnist_opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&mnist_inputs2, (TfLiteIntArray*)&mnist_outputs2, const_cast<void*>(static_cast<const void*>(&mnist_opdata2)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&mnist_inputs3, (TfLiteIntArray*)&mnist_outputs3, const_cast<void*>(static_cast<const void*>(&mnist_opdata3)), OP_RESHAPE, },
  { (TfLiteIntArray*)&mnist_inputs4, (TfLiteIntArray*)&mnist_outputs4, const_cast<void*>(static_cast<const void*>(&mnist_opdata4)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&mnist_inputs5, (TfLiteIntArray*)&mnist_outputs5, const_cast<void*>(static_cast<const void*>(&mnist_opdata5)), OP_SOFTMAX, },
  { (TfLiteIntArray*)&mnist_inputs6, (TfLiteIntArray*)&mnist_outputs6, nullptr, OP_DEQUANTIZE, },
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
  g_ctx.tensors_size = 13;
  for(size_t i = 0; i < 13; ++i) {
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

  for(size_t i = 0; i < 7; ++i) {
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
  for(size_t i = 0; i < 7; ++i) {
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
  11, 
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
  12, 
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
  for(size_t i = 0; i < 7; ++i) {
    TfLiteStatus status = g_registrations[nodes[i].used_op_index]->invoke(&g_ctx, &g_nodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}
