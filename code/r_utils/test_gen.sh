#!/bin/bash

./Anhydrate_test_gen_stream >> /tmp/Anhydrate/fifo1&
./Anhydrate_tx_video /tmp/Anhydrate/fifo1
