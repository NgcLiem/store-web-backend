class LFSR:
    def __init__(self, size, taps):
        self.register_bits = [0] * size
        self.feedback_taps = taps

    def set_initial_state(self, state):
        self.register_bits = state

    def shift(self):
        feedback = 0
        for tap in self.feedback_taps:
            feedback ^= self.register_bits[tap]
        output_bit = self.register_bits[0]
        self.register_bits.pop(0)
        self.register_bits.append(feedback)
        return output_bit

    def get_output(self):
        return self.register_bits[-1]

def a5_1_encrypt(key, input_data):
    R1 = LFSR(19, [0, 1, 2, 3, 4])
    R2 = LFSR(22, [0, 1, 2, 3, 4, 5, 6])
    R3 = LFSR(23, [0, 1, 2, 3, 4, 5, 6, 7, 8])

    R1.set_initial_state(key[:19])
    R2.set_initial_state(key[19:41])
    R3.set_initial_state(key[41:])

    keystream = []
    for _ in range(len(input_data)):
        output_R1 = R1.shift()
        output_R2 = R2.shift()
        output_R3 = R3.shift()
        majority = output_R1 + output_R2 + output_R3
        keystream.append(1 if majority >= 2 else 0)

    encrypted_data = [input_bit ^ keystream[i] for i, input_bit in enumerate(input_data)]
    return encrypted_data

# Test with key and data
key = [1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0]
input_data = [1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0]

output = a5_1_encrypt(key, input_data)
print("Encrypted Data:", output)
