#include <iostream>
#include <string>

#include "benchmark/benchmark.h"

#include "resource.h"

static void BM_CreateStringResource(benchmark::State& state) {
  for (auto _ : state)
    Resource<std::string>::Create("here-are-strings");
}
BENCHMARK(BM_CreateStringResource);

static void BM_CreateIntResource(benchmark::State& state) {
  for (auto _ : state)
    Resource<int>::Create("here-are-ints");
}
BENCHMARK(BM_CreateIntResource);

BENCHMARK_MAIN();
