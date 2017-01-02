#include "Rts.h"
#include <string.h>

HsInt
ghc_strlen( HsPtr a )
{
  return (strlen((char *)a));
}

HsInt
ghc_memcmp( HsPtr a1, HsPtr a2, HsInt len )
{
  return (memcmp((char *)a1, a2, len));
}

HsInt
ghc_memcmp_off( HsPtr a1, HsInt i, HsPtr a2, HsInt len )
{
  return (memcmp((char *)a1 + i, a2, len));
}

void
enableTimingStats( void )       /* called from the driver */
{
  RtsFlags.GcFlags.giveStats = ONELINE_GC_STATS;
}

void
setHeapSize( HsInt size )
{
  RtsFlags.GcFlags.heapSizeSuggestion = size / BLOCK_SIZE;
  if (RtsFlags.GcFlags.maxHeapSize != 0 &&
      RtsFlags.GcFlags.heapSizeSuggestion > RtsFlags.GcFlags.maxHeapSize) {
    RtsFlags.GcFlags.maxHeapSize = RtsFlags.GcFlags.heapSizeSuggestion;
  }
}
