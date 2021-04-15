#ifndef RR_GRAPH_BUILDER_H
#define RR_GRAPH_BUILDER_H

#include "rr_graph_storage.h"
#include "rr_spatial_lookup.h"

/* A data structure allows data modification on a routing resource graph 
 *
 * Note that the builder does not own the storage
 * It serves a virtual protocol for
 * - node_storage: store the node list 
 * - node_lookup: store a fast look-up for the nodes
 *
 * Note:
 * - This is the only data structre allowed to modify a routing resource graph
 *
 */
class RRGraphBuilder {
    /****************
     * Constructors
     ****************/
  public:
    RRGraphBuilder(t_rr_graph_storage* node_storage,
                   RRSpatialLookup* node_lookup);

    /* Disable copy constructors
     * This is to avoid any duplication of the object
     * as it is only interface allowed to modify routing resource graph
     */
    RRGraphBuilder(const RRGraphBuilder&) = delete;
    
    /* Disable copy assignment operator */
    void operator=(const RRGraphBuilder&) = delete;

    /****************
     * Mutators
     ****************/
  public:
    /* Return a writable object for rr_nodes */
    t_rr_graph_storage& node_storage();
    /* Return a writable object for update the fast look-up of rr_node */
    RRSpatialLookup& node_lookup();

    /****************
     * internal data storage
     ****************/
  private:
    /* TODO: When the refactoring effort finishes, 
     * the builder data structure will be the owner of the data storages. 
     * That is why the reference to storage/lookup is used here.
     * It can avoid a lot of code changes once the refactoring is finished 
     * (there is no function get data directly through the node_storage in DeviceContext).
     * If pointers are used, it may cause many codes in client functions 
     * or inside the data structures to be changed later.
     * That explains why the reference is used here temporarily
     */
    /* node-level storage including edge storages */
    t_rr_graph_storage& node_storage_;
    /* Fast look-up for rr nodes */
    RRSpatialLookup& node_lookup_;
};

#endif
