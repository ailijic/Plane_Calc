#pragma once

#define CONST __attribute__ ((const))
#define PURE __attribute__ ((pure))

#define UNUSED(expr) do { (void)(expr); } while (0)