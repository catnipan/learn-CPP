#pragma once

#include "../graph.h"

template <typename Tv, typename Te>
struct DijkstraPU {
  virtual void operator() (Graph<Tv, Te>* g, int uk, int v) {
    if (UNDISCOVERED == g->status(v)) {
      if (g->priority(v) > g->priority(uk) + g->weight(uk, v)) {
        g->priority(v) = g->priority(uk) + g->weight(uk, v);
        g->parent(v) = uk;
      }
    }
  }
};

template <typename Tv, typename Te>
void Graph<Tv, Te>::dijkstra(int s) {
  pfs(s, DijkstraPU<Tv, Te>{});
}