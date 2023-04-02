#include <torch/script.h>
#include<ATen/ATen.h>

using namespace at;

torch::Tensor reduction(torch::Tensor LayerOne_intrlved_embedding, torch::Tensor LayerTwo_intrlved_embedding,
                        torch::Tensor LayerThree_intrlved_embedding, torch::Tensor LayerFour_intrlved_embedding)
{ 
  at::TensorList embedding = (LayerOne_intrlved_embedding,LayerTwo_intrlved_embedding,
                                                LayerThree_intrlved_embedding,LayerFour_intrlved_embedding);
  at::Tensor concatenated_embedding = at::concat(embedding,0);
    
  torch::Tensor image_embedding = at::mean(concatenated_embedding,0);
    
  return image_embedding;
    
}

static auto reduction_registry = torch::RegisterOperators("Reduce::reduction", &reduction);