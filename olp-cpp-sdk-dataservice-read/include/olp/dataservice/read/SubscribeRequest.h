/*
 * Copyright (C) 2020-2021 HERE Europe B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 * License-Filename: LICENSE
 */

#pragma once

#include <string>
#include <utility>

#include <olp/dataservice/read/ConsumerProperties.h>
#include <olp/dataservice/read/Types.h>
#include <boost/optional.hpp>

namespace olp {
namespace dataservice {
namespace read {

/**
 * @brief Used to subscribe to a stream layer.
 */
class DATASERVICE_READ_API SubscribeRequest final {
 public:
  /**
   * @brief The subscription mode.
   */
  enum class SubscriptionMode : char {
    /**
     * A default option.
     *
     * The subscription mode used for applications that read
     * smaller volumes of data with a single subscription.
     */
    kSerial,
    /**
     * The subscription mode used for applications that read large volumes of
     * data in a parallel manner.
     */
    kParallel
  };
  /**
   * @brief Sets the subscription mode for the request.
   *
   * The default value is `kSerial`.
   *
   * @param mode The subscription mode.
   *
   * @return  A reference to the updated `SubscribeRequest` instance.
   */
  inline SubscribeRequest& WithSubscriptionMode(SubscriptionMode mode) {
    subscription_mode_ = mode;
    return *this;
  }

  /**
   * @brief Gets the subscription mode of the request.
   *
   * @return The subscription mode.
   */
  inline SubscriptionMode GetSubscriptionMode() const {
    return subscription_mode_;
  }

  /**
   * @brief (Optional) Sets the subscription ID used for the request.
   *
   * Generated by the HERE platform if missing. Must be UUID. Must be unique within
   * subscriptions.
   *
   * @param subscription_id The subscription ID.
   *
   * @return A reference to the updated `SubscribeRequest` instance.
   */
  inline SubscribeRequest& WithSubscriptionId(
      boost::optional<SubscriptionId> subscription_id) {
    subscription_id_ = std::move(subscription_id);
    return *this;
  }

  /**
   * @brief Gets the subscription ID of the request.
   *
   * @return The subscription ID.
   */
  inline const boost::optional<SubscriptionId>& GetSubscriptionId() const {
    return subscription_id_;
  }

  /**
   * @brief (Optional) Sets the consumer ID used for the request.
   *
   * Generated by the HERE platform if missing. Must be UUID.
   * Must be unique within the consumer group (group ID, HRN, layer ID, and
   * application ID (AID)).
   *
   * @param consumer_id The consumer ID.
   *
   * @return A reference to the updated `SubscribeRequest` instance.
   */
  inline SubscribeRequest& WithConsumerId(
      boost::optional<std::string> consumer_id) {
    consumer_id_ = std::move(consumer_id);
    return *this;
  }

  /**
   * @brief Gets the consumer ID of the request.
   *
   * @return The consumer ID.
   */
  inline const boost::optional<std::string>& GetConsumerId() const {
    return consumer_id_;
  }

  /**
   * @brief Sets the consumer properties for the request.
   *
   * @see The [Get Data from a Stream
   * Layer](https://developer.here.com/documentation/data-api/data_dev_guide/rest/getting-data-stream.html)
   * section in the Data API Developer Guide.
   *
   * @param properties The consumer properties.
   *
   * @return A reference to the updated `SubscribeRequest` instance.
   */
  inline SubscribeRequest& WithConsumerProperties(
      boost::optional<ConsumerProperties> properties) {
    consumer_properties_ = std::move(properties);
    return *this;
  }

  /**
   * @brief Gets the consumer properties of the request.
   *
   * @return The consumer properties.
   */
  inline const boost::optional<ConsumerProperties>& GetConsumerProperties()
      const {
    return consumer_properties_;
  }

 private:
  SubscriptionMode subscription_mode_{SubscriptionMode::kSerial};
  boost::optional<SubscriptionId> subscription_id_;
  boost::optional<std::string> consumer_id_;
  boost::optional<ConsumerProperties> consumer_properties_;
};

}  // namespace read
}  // namespace dataservice
}  // namespace olp
