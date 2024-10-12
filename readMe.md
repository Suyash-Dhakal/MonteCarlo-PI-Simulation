<h1>Monte Carlo Method for Estimating Pi</h1>

<p>This project implements the Monte Carlo method for estimating the value of Pi. The estimation is performed using both serial C code and a parallel implementation utilizing OpenMP. The experiments were conducted on an Apple MacBook Air M2 with 16GB of memory.</p>

<h2>Project Overview</h2>
<p>The Monte Carlo method is a statistical technique that uses random sampling to obtain numerical results. In this case, we use it to estimate the value of Pi by simulating random points in a unit square and counting how many fall within a quarter circle inscribed within that square.</p>

<h2>Implementation</h2>
<ul>
    <li><strong>Serial Implementation:</strong> A straightforward implementation of the Monte Carlo method using standard C, without parallel processing.</li>
    <li><strong>Parallel Implementation:</strong> An optimized version that leverages OpenMP to perform concurrent execution, improving the speed of the simulation.</li>
</ul>

<h2>Device Information</h2>
<p>The experiments were conducted on the following device:</p>
<ul>
    <li><strong>Device:</strong> Apple MacBook Air M2</li>
    <li><strong>Memory:</strong> 16GB</li>
</ul>

<h2>Files Included</h2>
<ul>
    <li><strong>monte_carlo_serial.c:</strong> Serial implementation of the Monte Carlo method for estimating Pi.</li>
    <li><strong>monte_carlo_parallel.c:</strong> Parallel implementation using OpenMP for estimating Pi.</li>
    <li><strong>convergence.txt:</strong> Data file containing convergence results for various sample sizes.</li>
    <li><strong>absolute_errors.txt:</strong> Data file containing the absolute errors of the Pi estimates compared to the actual value.</li>
</ul>

<h2>How to Compile and Run</h2>
<p>To compile and run the code, use the following commands:</p>
<ol>
    <li>For the serial implementation:</li>
    <pre><code>gcc monte_carlo_serial.c -o monte_carlo_serial</code></pre>
    <pre><code>./monte_carlo_serial</code></pre>

    <li>For the parallel implementation:</li>
    <pre><code>gcc monte_carlo_parallel.c -o monte_carlo_parallel -fopenmp</code></pre>
    <pre><code>./monte_carlo_parallel</code></pre>
</ol>

<h2>Conclusion</h2>
<p>This project demonstrates the effectiveness of the Monte Carlo method for estimating Pi, showcasing both serial and parallel implementations. The results indicate the convergence of the estimated value to the actual value of Pi as the number of sampled points increases.</p>

<!-- <h2>License</h2>
<p>This project is licensed under the MIT License - see the LICENSE file for details.</p> -->
