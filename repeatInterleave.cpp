#include <torch/script.h>
#include <ATen/ATen.h>

using namespace at;

torch::Tensor repeatInterleave(torch::Tensor layer_embedding)
{    
    torch::Tensor interleaved_embedding_array = at::repeat_interleave(layer_embedding,512/layer_embedding.size(1),0);

    interleaved_embedding_array = at::reshape(interleaved_embedding_array,{1,512});
    
    return interleaved_embedding_array;
}

static auto repeatInterleave_registry = torch::RegisterOperators("RepInterleave::repeatInterleave", &repeatInterleave);
