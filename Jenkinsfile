#!groovy

pipeline {
  agent {
    docker {
      image 'geodynamics/calypso-buildenv-bionic:latest'
      alwaysPull true
    }
  }

  options {
    timeout(time: 2, unit: 'HOURS')
  }

  stages {
    stage('Build') {
      steps {
        sh '''
          ./configure
           '''
        sh '''

        make
        '''
      }
    }
  }

  post { always { cleanWs() } }
}
