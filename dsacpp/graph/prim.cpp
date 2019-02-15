#pragma once

#include "../graph.h"

template <typename Tv, typename Te>
struct PrimPU {
  virtual void operator() (Graph<Tv, Te>* g, int uk, int v) {
    if (UNDISCOVERED == g->status(v)) {
      if (g->priority(v) > g->weight(uk, v)) {
        g->priority(v) = g->weight(uk, v);
        g->parent(v) = uk;
      }
    }
  }
};

template <typename Tv, typename Te>
void Graph<Tv, Te>::prim(int s) {
  pfs(s, PrimPU<Tv, Te>{});
}