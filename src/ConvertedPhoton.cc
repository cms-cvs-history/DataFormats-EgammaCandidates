
#include "DataFormats/EgammaCandidates/interface/ConvertedPhoton.h"

using namespace reco;

ConvertedPhoton::~ConvertedPhoton() { }

ConvertedPhoton * ConvertedPhoton::clone() const { 
  return new ConvertedPhoton( * this ); 
}

reco::SuperClusterRef ConvertedPhoton::superCluster() const {
  return superCluster_;
}

bool ConvertedPhoton::overlap( const Candidate & c ) const {
  const RecoCandidate * o = dynamic_cast<const RecoCandidate *>( & c );
  return ( o != 0 && 
	   ( checkOverlap( superCluster(), o->superCluster() ) )
	   );
  return false;
}
