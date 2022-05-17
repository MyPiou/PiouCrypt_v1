import numpy, pylab
import numpy as np
from sklearn.decomposition import NMF
np.set_printoptions(precision=2)
def generate_lattice(
    image_shape, lattice_vectors, center_pix='image', edge_buffer=2):
    if center_pix == 'image':
        center_pix = numpy.array(image_shape) // 2
    else:
        center_pix = numpy.array(center_pix) - (numpy.array(image_shape) // 2)
        lattice_components = numpy.linalg.solve(
            numpy.vstack(lattice_vectors[:2]).T,
            center_pix)
        lattice_components -= lattice_components // 1
        center_pix = (lattice_vectors[0] * lattice_components[0] +
                      lattice_vectors[1] * lattice_components[1] +
                      numpy.array(image_shape)//2)
    num_vectors = int( 
        max(image_shape) / numpy.sqrt(lattice_vectors[0]**2).sum())
    lattice_points = []
    lower_bounds = numpy.array((edge_buffer, edge_buffer))
    upper_bounds = numpy.array(image_shape) - edge_buffer
    for i in range(-num_vectors, num_vectors):
        for j in range(-num_vectors, num_vectors):
            lp = i * lattice_vectors[0] + j * lattice_vectors[1] + center_pix
            if all(lower_bounds < lp) and all(lp < upper_bounds):
                lattice_points.append(lp)
    return lattice_points

lattice_vectors = [
    numpy.array([-40., -1.]),
    numpy.array([ 18., -37.])]
image_shape = (1000, 1000)
spots = generate_lattice(image_shape, lattice_vectors)

fig=pylab.figure()
pylab.plot([p[1] for p in spots], [p[0] for p in spots], '.')
pylab.axis('equal')
fig.savefig('foo.png')
fig.show()

model = NMF(n_components=2, init='random', random_state=0)
W = model.fit_transform(spots)
H = model.components_

np.savetxt('OEA-Key.txt', W)

np.set_printoptions(precision=2)

np.savetxt('W.txt', np.around(W,2))
np.savetxt('H.txt', np.around(H,2))
