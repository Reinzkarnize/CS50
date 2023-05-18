document.addEventListener('DOMContentLoaded', function() {
  let images = document.querySelectorAll('[id="slideshow"]');
  let prevButton = document.querySelector('.fa-solid.fa-backward');
  let nextButton = document.querySelector('.fa-solid.fa-forward');
  let autoMode = document.querySelector('.fa-solid.fa-play')

  let currentIndex = 0;

  for (let i = 1; i < images.length; i++) {
      images[i].style.display = 'none';
  }

  prevButton.addEventListener('click', function() {
    images[currentIndex].style.display = 'none';
    currentIndex = (currentIndex - 1 + images.length) % images.length;
    images[currentIndex].style.display = 'block';
    updateButtons();
  });

  nextButton.addEventListener('click', function() {
    images[currentIndex].style.display = 'none';
    currentIndex = (currentIndex + 1) % images.length;
    images[currentIndex].style.display = 'block';
    updateButtons();
  });

  let isAutoModeOn = false;
  let intervalId;

  autoMode.addEventListener('click', function() {
    if (isAutoModeOn) {
      autoMode.classList = "fa-solid fa-play";

      clearInterval(intervalId);
      isAutoModeOn = false;
    }

    else {
      autoMode.classList = "fa-solid fa-pause";
      intervalId = setInterval(function() {
        images[currentIndex].style.display = 'none';
        currentIndex = (currentIndex + 1) % images.length;
        images[currentIndex].style.display = 'block';
        updateButtons();
      }, 3000);

      isAutoModeOn = true;
    }
  })
})
