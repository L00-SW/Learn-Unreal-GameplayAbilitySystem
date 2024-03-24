#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Center, Color) if(GetWorld()) DrawDebugSphere(GetWorld(), Center, 8.f, 12, Color, false, -1.f);
#define DRAW_LINE(StartLocation, EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, false, -1.f);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Blue, false, -1.f);
#define DRAW_VECTOR(StartLocation, EndLocation) if(GetWorld())\
{\
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Blue, false, -1.f); \
	DrawDebugPoint(GetWorld(), StartLocation, 15.f, FColor::Blue, false, -1.f); \
}