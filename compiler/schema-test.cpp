#include "schema.capnp.h"
#include <gtest/gtest.h>

static const uint8_t simple_schema[] = {
  0x00, 0x00, 0x00, 0x00, 0x5f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x6d, 0x05, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x03, 0x00, 0x04, 0x00, 0x73, 0x4d, 0xd2, 0x75, 0x6b, 0xff, 0xe1, 0xbe,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x29, 0x00, 0x00, 0x00, 0xb2, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00,
  0x3d, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x09, 0xb7, 0x71, 0x68, 0xc7, 0x34, 0xc8, 0xff, 0x73, 0x4d, 0xd2, 0x75, 0x6b, 0xff, 0xe1, 0xbe,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00, 0x00,
  0x41, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x63, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72,
  0x2f, 0x73, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x61, 0x70, 0x6e, 0x70, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x09, 0xb7, 0x71, 0x68, 0xc7, 0x34, 0xc8, 0xff,
  0x01, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x46, 0x6f, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x63, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72,
  0x2f, 0x73, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x61, 0x70, 0x6e, 0x70, 0x3a, 0x46, 0x6f,
  0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x62, 0x6f, 0x64, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x67, 0x02, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x29, 0x01, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x2d, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x2c, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x49, 0x01, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x4d, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x4c, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x69, 0x01, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x6d, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x6c, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x89, 0x01, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0x8d, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x8c, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x05, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xa9, 0x01, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0xad, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0xac, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x06, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc9, 0x01, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0xcd, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0xcc, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe9, 0x01, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0xed, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0xec, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x08, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x09, 0x02, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x0d, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x0c, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x09, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x29, 0x02, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x2d, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x2c, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x49, 0x02, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x4d, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x4c, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0b, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x69, 0x02, 0x00, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x6d, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x6c, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x89, 0x02, 0x00, 0x00, 0x6a, 0x00, 0x00, 0x00, 0x8d, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x8c, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0d, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xa9, 0x02, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0xad, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0xac, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0e, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc9, 0x02, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0xcd, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0xcc, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x0f, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xe9, 0x02, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0xed, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0xec, 0x02, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x10, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x09, 0x03, 0x00, 0x00, 0x52, 0x00, 0x00, 0x00, 0x0d, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x0c, 0x03, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x11, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x29, 0x03, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x2d, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x2c, 0x03, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x12, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x49, 0x03, 0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x4d, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x4c, 0x03, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x13, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x69, 0x03, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x6d, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x6c, 0x03, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x75, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x56, 0x61,
  0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x6f, 0x6f, 0x6c, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x38, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x31, 0x36, 0x56, 0x61, 0x6c,
  0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x56, 0x61, 0x6c,
  0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x36, 0x34, 0x56, 0x61, 0x6c,
  0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x69, 0x6e, 0x74, 0x38, 0x56, 0x61, 0x6c,
  0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x69, 0x6e, 0x74, 0x31, 0x36, 0x56, 0x61,
  0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x69, 0x6e, 0x74, 0x33, 0x32, 0x56, 0x61,
  0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x6f, 0x69, 0x64, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x33, 0x32, 0x56,
  0x61, 0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x36, 0x34, 0x56,
  0x61, 0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x61, 0x74, 0x61, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x69, 0x73, 0x74, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x65, 0x6e, 0x75, 0x6d, 0x56, 0x61, 0x6c, 0x75,
  0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x56, 0x61,
  0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x66, 0x61, 0x63,
  0x65, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x56, 0x61,
  0x6c, 0x75, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x4d, 0xd2, 0x75, 0x6b, 0xff, 0xe1, 0xbe,
};

TEST(Schema, ReadSimple) {
  struct capn ctx;
  ASSERT_EQ(0, capn_init_mem(&ctx, simple_schema, sizeof(simple_schema), 0));

  CodeGeneratorRequest_ptr root = {capn_getp(capn_root(&ctx), 0, 1)};
  EXPECT_EQ(CAPN_STRUCT, root.p.type);

  struct CodeGeneratorRequest req;
  read_CodeGeneratorRequest(&req, root);
  for (int i = 0; i < req.nodes.p.len; i++) {
  }
}

