// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "lrn_kernel_base.h"
#include "vector"

namespace kernel_selector {
class LRNKernelWithinChannelByxfOpt : public LRNKernelBase {
public:
    using Parent = LRNKernelBase;
    LRNKernelWithinChannelByxfOpt() : LRNKernelBase("lrn_within_channel_byxf_opt") {}
    virtual ~LRNKernelWithinChannelByxfOpt() {}

    KernelsData GetKernelsData(const Params& params, const optional_params& options) const override;
    KernelsPriority GetKernelsPriority(const Params& params, const optional_params& options) const override;
    ParamsKey GetSupportedKey() const override;

private:
    DispatchData SetDefault(const lrn_params& params) const override;
    std::vector<FusedOpType> GetSupportedFusedOps() const override {
        return { FusedOpType::QUANTIZE,
                 FusedOpType::SCALE,
                 FusedOpType::ACTIVATION };
    }
    bool Validate(const Params& params, const optional_params& options) const override;
    JitConstants GetJitConstants(const lrn_params& params, const DispatchData& dispatchData) const override;
};
}  // namespace kernel_selector
