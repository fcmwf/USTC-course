from sklearn.datasets import load_wine
import numpy as np 
import matplotlib.pyplot as plt
from gensim.models import KeyedVectors

def get_kernel_function(kernel: str):
    if kernel == "linear":
        return lambda X: np.dot(X, X.T)
    elif kernel == "poly":
        return lambda X: (np.dot(X, X.T) + 1) ** 2
    elif kernel == "rbf":
        def rbf_kernel(X, gamma=1):
            sq_dists = np.sum(X ** 2, axis=1).reshape(-1, 1) + np.sum(X ** 2, axis=1) - 2 * np.dot(X, X.T)
            return np.exp(-gamma * sq_dists)
        return rbf_kernel
    else:
        raise ValueError(f"Unsupported kernel: {kernel}")

def pca(X,k):

    _ , n_features = X.shape
    mean=np.array([np.mean(X[:,i]) for i in range(n_features)])
    #normalization
    norm_X=X-mean
    #scatter matrix
    scatter_matrix=np.dot(np.transpose(norm_X),norm_X)
    #Calculate the eigenvectors and eigenvalues
    eig_val, eig_vec = np.linalg.eig(scatter_matrix)
    eig_pairs = [(np.abs(eig_val[i]), eig_vec[:,i]) for i in range(n_features)]
    # sort eig_vec based on eig_val from highest to lowest
    eig_pairs.sort(reverse=True)
    # select the top k eig_vec
    feature=np.array([ele[1] for ele in eig_pairs[:k]])
    #get new data
    data=np.dot(norm_X,np.transpose(feature))
    return data


class KMeans:
    def __init__(self, n_clusters:int=3, max_iter:int=10) -> None:
        self.n_clusters = n_clusters
        self.max_iter = max_iter
        self.centers = None
        self.labels = None

    # Randomly initialize the centers
    def initialize_centers(self, points):
        n_samples, n_dims = points.shape

        self.centers = np.zeros((self.n_clusters, n_dims))
        for k in range(self.n_clusters):
            random_index = np.random.choice(n_samples, size=10, replace=False)
            self.centers[k] = points[random_index].mean(axis=0)
        
        return self.centers
    
    # Assign each point to the closest center
    def assign_points(self, points):
        n_samples, n_dims = points.shape
        self.labels = np.zeros(n_samples)

        for i, point in enumerate(points):
            distances = np.linalg.norm(self.centers - point, axis=1)
            self.labels[i] = np.argmin(distances)
        
        return self.labels

    # Update the centers based on the new assignment of points
    def update_centers(self, points):
        for k in range(self.n_clusters):
            cluster_points = points[self.labels == k]
            if len(cluster_points) > 0:
                self.centers[k] = cluster_points.mean(axis=0)

    # k-means clustering
    def fit(self, points):
        self.initialize_centers(points)

        for _ in range(self.max_iter):
            old_centers = np.copy(self.centers)

            self.labels = self.assign_points(points)
            self.update_centers(points)

            if np.all(old_centers == self.centers):
                break

    # Predict the closest cluster each sample in X belongs to
    def predict(self, points):
        return self.assign_points(points)
    
def load_data():
    words = [
        'computer', 'laptop', 'minicomputers', 'PC', 'software', 'Macbook',
        'king', 'queen', 'monarch','prince', 'ruler','princes', 'kingdom', 'royal',
        'man', 'woman', 'boy', 'teenager', 'girl', 'robber','guy','person','gentleman',
        'banana', 'pineapple','mango','papaya','coconut','potato','melon',
        'shanghai','HongKong','chinese','Xiamen','beijing','Guilin',
        'disease', 'infection', 'cancer', 'illness', 
        'twitter', 'facebook', 'chat', 'hashtag', 'link', 'internet',
    ]
    w2v = KeyedVectors.load_word2vec_format('./data/GoogleNews-vectors-negative300.bin', binary = True)
    vectors = []
    for w in words:
        vectors.append(w2v[w].reshape(1, 300))
    vectors = np.concatenate(vectors, axis=0)
    return words, vectors

if __name__=='__main__':
    words, data = load_data()
    data_pca = pca(data,2)


    kmeans = KMeans(n_clusters=7)
    kmeans.fit(data_pca)
    clusters = kmeans.predict(data_pca)

    # plot the data
    
    plt.figure()
    plt.scatter(data_pca[:, 0], data_pca[:, 1], c=clusters)
    for i in range(len(words)):
        plt.annotate(words[i], data_pca[i, :]) 
    plt.title("PB21051012")
    plt.savefig("PCA_KMeans.png")