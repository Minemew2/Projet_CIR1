#ifndef RESEARCH_H
#define RESEARCH_H

#include "create.h"

Film **moviesByRealisator(Node_realisator* root, char requestedRealisator);

Realisator *topRealisator(Realisator **ByMoviesNumber);

#endif