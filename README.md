# Perceptron from Scratch

An implementation of the perceptron learning algorithm in C++ from scratch, trained on the Iris flower dataset to classify Sentosa vs Versicolor flowers. 

This was built as a learning exercise to understand the inner workings of the perceptron algorithm. Rather than using a high level library like scikit-learn, this is implemented in raw C++ to build a deep understanding of the underlying mechanics.




## How It Works

### 1. The Weighted Sum 

The perceptron takes a n -dimensional input vector x, computes a dot product with a weight vector w, and adds a bias term b to produce a weighted sum z = w . x + b. Mathematically, this can be expressed as:

$$z = \sum_{i=1}^{n} w_i x_i + b$$

Where:
- $w_i$ are the weights learned by the model (assigning importance to each input feature)
- $x_i$ are the inputs (petal length, petal width, etc.)
- $b$ is the bias term (used to shift the decision boundary)

### 2. The Activation Function

The weighted sum is passed to an activation function to produce the output of the perceptron, which is 0 or 1. In this implementation, we use a step function as the activation function:

$$f(z) = \begin{cases} 1 & \text{if } z \geq 0 \\ 0 & \text{if } z < 0 \end{cases}$$



### 3. The Learning Rule 

The perceptron has a very simple learning rule to update the weights and bias based on the error between the predicted output and the true label. The update rule is as follows:

$$w_i \leftarrow w_i + \alpha \cdot e \cdot x_i$$

$$b \leftarrow b + \alpha \cdot e$$

Where:
- $\alpha$ = learning rate (controls step size)
- $e$ = error = correct label − predicted label

If the prediction is correct, the error is 0 and nothing changes.
If the prediction is incorrect, the weights and bias are updated in the direction that would correct the error. This process is repeated for each training example until the model converges (i.e., makes no more errors on the training data).

### 4. Convergence

A beautiful property of the perceptron learning algorithm is that it is guaranteed to converge to a solution that correctly classifies the training data if the data is linearly separable. This means that if there exists a hyperplane that can separate the two classes, the perceptron will find it in a finite number of iterations. 

The mathematical proof of this fact is truly fascinating; a complete proof can be found here:

[Perceptron Convergence Theorem - Cornell CS4780](https://www.cs.cornell.edu/courses/cs4780/2018fa/lectures/lecturenote03.html)






## Project Structure
```
cpp-perceptron/
├── data/
│   └── iris.csv          # Iris flower dataset
├── includes/
│   ├── perceptron.hpp    # Perceptron class declaration
│   └── dataloader.hpp    # CSV loader declaration
├── src/
│   ├── perceptron.cc     # Perceptron implementation
│   ├── dataloader.cc     # CSV parsing implementation
│   └── driver.cc         # Main program
└── Makefile
```

---
## Build & Run

**Requirements:** g++ with C++17 support
```bash
make
./perceptron
```

To recompile from scratch:
```bash
make clean
make
```

---

## Dataset

Uses the [UCI Iris dataset](https://archive.ics.uci.edu/ml/datasets/iris).
Only **Setosa** (label 1) and **Versicolor** (label 0) are used since 
the perceptron is a binary classifier.

Each sample has 4 features:
- Sepal length
- Sepal width
- Petal length
- Petal width

---

## Example Output
```
Epoch 1/100 | Errors: 2
Epoch 2/100 | Errors: 1
Epoch 3/100 | Errors: 0
Training complete after 3 epochs.

Accuracy: 100/100 (100%)
```

---

## Limitations 
- Can only classify linearly separable data, so it fails to learn non linear problems like XOR problem
- Evaluation is done on the training data, no separate test set
- Only binary classification (Setosa vs Versicolor), ignores Virginica
- It only uses a step activation function, which is not differentiable and limits the learning capabilities of the model

## Future Improvements
- Add a seperate test set to evaluate the model's performance on unlabeled data
- Implement a multi-layer perceptron to learn non-linear problems like the XOR problem
- Replace the step function with a differentiable activation function like sigmoid or ReLU to improve learning capabilities 

## What I Learned

Implementing the perceptron from scratch taught me the importance of linear algebra in machine learning. I gained a deeper understanding and appreciation of why the learning rule actually works. The most exciting part was to see the algorithm fail to learn the XOR problem, a very good demonstration of how the perceptron is limited to learning only linearly separable data, and how this led to the development of more complex models like multi-layer perceptron and neural networks. Overall, it was a very valuable experience that solidified my understanding of single layer perceptron and motivates me to learn about multi-layer perceptron and backpropagation next!
